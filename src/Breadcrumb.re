module Divider = {
  let component = ReasonReact.statelessComponent("Divider");

  let make = (~divider, _children) => {
    ...component,
    render: _ => <i className="c-breadcrumb__divider"> divider </i>,
  };
};

module Item = {
  include BreadcrumbItem;
};

let component = ReasonReact.statelessComponent("Breadcrumb");

let make = (~divider="/", _children) => {
  ...component,
  render: _ => {
    let sep = <Divider divider={ReasonReact.string(divider)} />;

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

[@bs.deriving abstract]
type jsProps = {
  divider: Js.nullable(string),
  children: array(ReasonReact.reactElement),
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~divider=?Js.Nullable.toOption(jsProps->dividerGet),
      jsProps->childrenGet,
    )
  );
