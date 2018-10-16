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
        isSvg ? "currentColor" : "inherit";
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
      <span className=classNames>
        {ReasonReact.string({j|\u200B|j})}
        <Feather name size color />
      </span>;
    } else {
      <i style className=classNames />;
    };
  },
};
