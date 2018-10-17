let component = ReasonReact.statelessComponent("Breadcrumb.Item");

let make = _children => {
  ...component,
  render: _ => <div className="c-breadcrumb__item"> ..._children </div>,
};

[@bs.deriving abstract]
type jsProps = {children: array(ReasonReact.reactElement)};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(jsProps->childrenGet)
  );
