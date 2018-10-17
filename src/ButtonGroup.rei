let default: ReasonReact.reactClass;

let make:
  (~size: Size.size=?, array(ReasonReact.reactElement)) =>
  ReasonReact.componentSpec(
    ReasonReact.stateless,
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );
