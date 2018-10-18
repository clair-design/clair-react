open Utils;

let component = ReasonReact.statelessComponent("Chip");
let emptyStyle = ReactDOMRe.Style.make();

let computeProps = (~color, ~size, ~closable) => {
  let isPresetColor = Color.isPresetColor(color);
  let colorStr = Color.toLiteral(color);

  let styleObj =
    if (!isPresetColor) {
      ReactDOMRe.Style.make(~backgroundColor=colorStr, ());
    } else {
      emptyStyle;
    };

  let classNames =
    List.fold_left(
      (a, b) => a ++ " " ++ b,
      "c-chip__wrapper",
      [
        "is-" ++ Size.toLiteral(size),
        if (closable) {"c-chip--closable"} else {""},
        if (isPresetColor) {
          "c-chip--" ++ colorStr;
        } else {
          "";
        },
      ],
    );
  (classNames, styleObj);
};

let make =
    (
      ~size: Size.size=Size.Medium,
      ~label="",
      ~color: Color.color=Color.Color(""),
      ~closable=false,
      ~onClose=?,
      _children,
    ) => {
  let (classNames, styleObj) = computeProps(~color, ~size, ~closable);

  {
    ...component,
    render: _ =>
      <div className=classNames style=styleObj>
        <span> ..._children </span>
        {
          Array.length(_children) === 0 ?
            <span className="c-chip__label">
              {ReasonReact.string(label)}
            </span> :
            ReasonReact.null
        }
        {
          closable ?
            <span onClick=?onClose>
              <Icon name=Feather.x color="currentColor" />
            </span> :
            ReasonReact.null
        }
      </div>,
  };
};

[@bs.deriving abstract]
type jsProps = {
  label: Js.nullable(string),
  size: Js.nullable(string),
  color: Js.nullable(string),
  closable: Js.nullable(bool),
  onClose: Js.nullable(ReactEvent.Mouse.t => unit),
  children: Js.nullable(array(ReasonReact.reactElement)),
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(
      ~label=?Js.Nullable.toOption(jsProps->labelGet),
      ~size=Size.fromNullableJsProps(jsProps->sizeGet),
      ~color=Color.fromNullableJsProps(jsProps->colorGet),
      ~closable=?Js.Nullable.toOption(jsProps->closableGet),
      ~onClose=?Js.Nullable.toOption(jsProps->onCloseGet),
      ensureChildren(jsProps->childrenGet),
    )
  );
