let component = ReasonReact.statelessComponent("Divider");
let make = _children => {
  ...component,
  render: _ => <div className="flex-center"> <div> ..._children </div> </div>,
};
