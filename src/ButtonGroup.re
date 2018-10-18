let component = ReasonReact.statelessComponent("Button.Group");
let make = (~size=?, _children) => {
  ...component,
  render: _ => {
    let className =
      switch (size) {
      | None => "c-button-group"
      | Some(size) => "c-button-group is-" ++ Size.toLiteral(size)
      };
    <div className> ..._children </div>;
  },
};

[@bs.deriving abstract]
type jsProps = {
  size: Js.nullable(string),
  children: array(ReasonReact.reactElement),
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~size=Size.fromNullableJsProps(jsProps->sizeGet),
      jsProps->childrenGet,
    )
  );
