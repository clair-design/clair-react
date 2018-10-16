type state = {btnRef: ref(option(Dom.element))};

type action =
  | SetRef
  | Toggle;

let component = ReasonReact.reducerComponent("Button");

type btnSize =
  | XS
  | SM
  | MD
  | LG
  | XL;

let getSize = size =>
  switch (size) {
  | XS => "xs"
  | SM => "sm"
  | MD => "md"
  | LG => "lg"
  | XL => "xl"
  };

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
      ~href=?,
      ~size: btnSize=MD,
      ~icon: string="",
      ~autofocus=false,
      _children,
    ) => {
  ...component,
  initialState: () => {btnRef: ref(None)},
  reducer: (action, _) =>
    switch (action) {
    | SetRef => ReasonReact.NoUpdate
    | Toggle => ReasonReact.NoUpdate
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
      "c-button--" ++ getSize(size),
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
    | None => <button className ref={self.handle(setBtnRef)}> frag </button>
    | Some(s) =>
      <button className onClick=(_ => ReasonReact.Router.push(s))>
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
  size: string,
  icon: Js.nullable(string),
  autofocus: Js.nullable(bool),
};

let jsComponent =
  ReasonReact.wrapReasonForJs(
    ~component,
    jsProps => {
      let size =
        switch (jsProps->sizeGet) {
        | "xs" => XS
        | "sm" => SM
        | "md" => MD
        | "lg" => LG
        | "xl" => XL
        | _ => MD
        };
      Js.log("xx");
      make(
        ~size,
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
