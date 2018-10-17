type state = {btnRef: ref(option(Dom.element))};
type action =
  | SetRef;

let make:
  (
    ~primary: bool=?,
    ~success: bool=?,
    ~warning: bool=?,
    ~danger: bool=?,
    ~round: bool=?,
    ~outline: bool=?,
    ~flat: bool=?,
    ~loading: bool=?,
    ~disabled: bool=?,
    ~href: string=?,
    ~size: Size.size=?,
    ~icon: string=?,
    ~autofocus: bool=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.componentSpec(
    state,
    state,
    ReasonReact.noRetainedProps,
    ReasonReact.noRetainedProps,
    action,
  );

let default: ReasonReact.reactClass;

module Group: {
  let make:
    (~size: Size.size=?, array(ReasonReact.reactElement)) =>
    ReasonReact.componentSpec(
      ReasonReact.stateless,
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless,
    );
};
