[@bs.val] external requireCSS: string => unit = "require";
[@bs.val] external requireAssetURI: string => string = "require";

[@bs.val] external hot: bool = "module.hot";
[@bs.val] external accept: unit => unit = "module.hot.accept";

let focusElement: Dom.element => unit = [%bs.raw
  {|
function (element) {
  element && element.focus()
}
  |}
];

let fromNullableJsProps =
    (prop: Js.nullable('a), defaultVal: 'b, f: 'a => 'b) =>
  switch (Js.Nullable.toOption(prop)) {
  | Some(str) => f(str)
  | None => defaultVal
  };

let ensureChildren = (arr: Js.nullable(array('a))) =>
  switch (Js.Nullable.toOption(arr)) {
  | Some(children) => children
  | None => [||]
  };
