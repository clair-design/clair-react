let component = ReasonReact.statelessComponent("Stage");
let make = _children => {
  ...component,
  render: _ => <div className="flex-center"> <div> ..._children </div> </div>,
};

[@bs.deriving abstract]
type jsProps = {children: array(ReasonReact.reactElement)};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(jsProps->childrenGet)
  );
