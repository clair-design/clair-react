let make:
  (
    ~name: string,
    ~type_: string=?,
    ~size: string=?,
    ~valign: string=?,
    ~color: string=?,
    ~ligature: bool=?,
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
