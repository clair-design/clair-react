let component = ReasonReact.statelessComponent("Icon");

let make =
    (
      ~name: string,
      ~type_="feather",
      ~size="1em",
      ~valign="baseline",
      ~color="",
      ~ligature=false,
      _children,
    ) => {
  ...component,
  render: _self => {
    let isSvg = type_ === "feather";
    let classNames = {
      let prefix = type_ !== "" ? type_ ++ "-" : "";
      "c-icon " ++ type_ ++ " " ++ prefix ++ name;
    };
    let iconColor =
      if (color === "") {
        "inherit";
      } else {
        color;
      };

    let style =
      ReactDOMRe.Style.make(
        ~color=iconColor,
        ~fontSize=size,
        ~verticalAlign=valign,
        (),
      );

    if (ligature) {
      <i style className=classNames> {ReasonReact.string(name)} </i>;
    } else if (isSvg) {
      <span style className=classNames>
        {ReasonReact.string({j|\u200B|j})}
        <Feather name size color />
      </span>;
    } else {
      <i style className=classNames />;
    };
  },
};

[@bs.deriving abstract]
type jsProps = {
  name: string,
  type_: Js.nullable(string),
  size: Js.nullable(string),
  valign: Js.nullable(string),
  color: Js.nullable(string),
  ligature: Js.nullable(bool),
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~name=jsProps->nameGet,
      ~type_=?Js.Nullable.toOption(jsProps->type_Get),
      ~size=?Js.Nullable.toOption(jsProps->sizeGet),
      ~valign=?Js.Nullable.toOption(jsProps->valignGet),
      ~color=?Js.Nullable.toOption(jsProps->colorGet),
      ~ligature=?Js.Nullable.toOption(jsProps->ligatureGet),
      [||],
    )
  );
