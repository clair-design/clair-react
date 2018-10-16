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
