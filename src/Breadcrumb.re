module Divider = {
  let component = ReasonReact.statelessComponent("Divider");

  let make = (~divider="", _children) => {
    ...component,
    render: _ =>
      <i className="c-breadcrumb__divider">
        {ReasonReact.string(divider)}
      </i>,
  };
};

module Item = {
  let component = ReasonReact.statelessComponent("Breadcrumb.Item");

  let make = _children => {
    ...component,
    render: _ => <div className="c-breadcrumb__item"> ..._children </div>,
  };
};

let component = ReasonReact.statelessComponent("Breadcrumb");

let make = (~divider="/", _children) => {
  ...component,
  render: _ => {
    let sep = <Divider divider />;

    let start = ref(0);
    let len = Array.length(_children);
    let children =
      Array.fold_left(
        (acc, child) => {
          start := start^ + 1;
          if (start^ < len) {
            Array.append(acc, [|child, sep|]);
          } else {
            Array.append(acc, [|child|]);
          };
        },
        [||],
        _children,
      );

    /* https://reasonml.github.io/docs/en/jsx.html#children-spread */
    <nav className="c-breadcrumb"> ...children </nav>;
  },
};
