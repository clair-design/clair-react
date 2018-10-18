let make:
  (
    ~size: Size.size=?,
    ~label: string=?,
    ~color: Color.color=?,
    ~closable: bool=?,
    ~onClose: ReactEvent.Mouse.t => unit=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.componentSpec(
    ReasonReact.stateless,
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );
let default: ReasonReact.reactClass;
