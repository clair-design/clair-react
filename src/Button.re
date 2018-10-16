type btnSize = Size.size;
type state = {btnRef: ref(option(Dom.element))};

type action =
  | SetRef;

let component = ReasonReact.reducerComponent("Button");

let make =
    (
      ~primary=false,
      ~success=false,
      ~warning=false,
      ~danger=false,
      ~round=false,
      ~outline=false,
      ~flat=false,
      ~loading=false,
      ~disabled=false,
      ~href=?,
      ~size: btnSize=Size.Medium,
      ~icon: string="",
      ~autofocus=false,
      ~onClick=?,
      _children,
    ) => {
  ...component,
  initialState: () => {btnRef: ref(None)},
  reducer: (action, _) =>
    switch (action) {
    | SetRef => ReasonReact.NoUpdate
    },
  didMount: self =>
    switch (self.state.btnRef^) {
    | None => ()
    | Some(btn) => Utils.focusElement(btn)
    },
  render: self => {
    let iconName = loading ? "loader" : icon;

    let classes = [
      primary ? "c-button--primary" : "",
      success ? "c-button--success" : "",
      warning ? "c-button--warning" : "",
      danger ? "c-button--danger" : "",
      round ? "c-button--round" : "",
      outline ? "c-button--outline" : "",
      flat ? "c-button--flat" : "",
      loading ? "c-button--loading" : "",
      "c-button--" ++ Size.toLiteral(size),
    ];

    let className =
      List.fold_left(
        (acc, item) =>
          if (item === "") {
            acc;
          } else {
            acc ++ " " ++ item;
          },
        "c-button",
        classes,
      );

    let frag =
      <>
        {
          iconName === "" ?
            ReasonReact.null :
            <Icon color="currentColor" name=iconName valign="middle" />
        }
        <span> ..._children </span>
      </>;
    let setBtnRef = (theRef, {ReasonReact.state}) =>
      if (autofocus) {
        state.btnRef := Js.Nullable.toOption(theRef);
      };

    switch (href) {
    | None =>
      <button onClick=?onClick className disabled ref={self.handle(setBtnRef)}> frag </button>
    | Some(s) =>
      <button className disabled onClick=(_ => ReasonReact.Router.push(s))>
        frag
      </button>
    };
  },
};

[@bs.deriving abstract]
type jsProps = {
  primary: Js.nullable(bool),
  success: Js.nullable(bool),
  warning: Js.nullable(bool),
  danger: Js.nullable(bool),
  round: Js.nullable(bool),
  outline: Js.nullable(bool),
  flat: Js.nullable(bool),
  loading: Js.nullable(bool),
  href: Js.nullable(string),
  size: Js.nullable(string),
  icon: Js.nullable(string),
  autofocus: Js.nullable(bool),
};

let default =
  ReasonReact.wrapReasonForJs(
    ~component,
    jsProps => {
      let size = Js.Nullable.toOption(jsProps->sizeGet);

      make(
        ~size=
          switch (size) {
          | None => Size.Medium
          | Some(str) => Size.fromLiteral(str)
          },
        ~href=?Js.Nullable.toOption(jsProps->hrefGet),
        ~primary=?Js.Nullable.toOption(jsProps->primaryGet),
        ~success=?Js.Nullable.toOption(jsProps->successGet),
        ~warning=?Js.Nullable.toOption(jsProps->warningGet),
        ~danger=?Js.Nullable.toOption(jsProps->dangerGet),
        ~round=?Js.Nullable.toOption(jsProps->roundGet),
        ~outline=?Js.Nullable.toOption(jsProps->outlineGet),
        ~flat=?Js.Nullable.toOption(jsProps->flatGet),
        ~loading=?Js.Nullable.toOption(jsProps->loadingGet),
        ~autofocus=?Js.Nullable.toOption(jsProps->autofocusGet),
        [||],
      );
    },
  );

module Group = {
  let component = ReasonReact.statelessComponent("Button.Group");
  let make = (~size=?, _children) => {
    ...component,
    render: _ => {
      let className =
        switch (size) {
        | None => "c-button-group"
        | Some(size) =>
          "c-button-group is-" ++ Size.toLiteral(size)
        };
      <div className> ..._children </div>;
    },
  };
};
