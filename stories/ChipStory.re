open BsStorybook.Story;

let _module = [%bs.raw "module"];
[@bs.val] external alert: string => unit = "alert";

module ChipClosabelDemo = {
  type state = {closed: bool};

  type action =
    | Close
    | Recover;

  let component = ReasonReact.reducerComponent("ChipClosabelDemo");
  let make = _children => {
    ...component,
    initialState: _ => {closed: false},
    reducer: (action, _) =>
      switch (action) {
      | Close => ReasonReact.Update({closed: true})
      | Recover => ReasonReact.Update({closed: false})
      },
    render: self =>
      <Stage>
        {
          self.state.closed ?
            ReasonReact.null :
            <Chip
              color=Color.Purple
              closable=true
              label="closea chip"
              onClose={_ => self.send(Close)}
            />
        }
      </Stage>,
  };
};

storiesOf("Chip", _module)
->(
    add("chip", () =>
      <Stage>
        {
          ReasonReact.array(
            Array.map(
              color =>
                <Chip
                  label={Color.toLiteral(color)}
                  color
                  key={Color.toLiteral(color)}
                />,
              Color.presetColors,
            ),
          )
        }
      </Stage>
    )
  )
->(
    add("size", () =>
      <Stage>
        <Chip label="small" size=Size.Small />
        <Chip label="normal" size=Size.Medium />
      </Stage>
    )
  )
->(add("close event", () => <ChipClosabelDemo />))
->(
    add("custom color", () =>
      <Stage>
        <Chip label="#336774" color={Color.Color("#336774")} />
        <Chip label="#724832" color={Color.Color("#724832")} />
        <Chip label="#516E41" color={Color.Color("#516E41")} />
      </Stage>
    )
  )
->(
    add("custom content", () =>
      <Stage>
        <Chip color=Color.Blue>
          <a href="https://twiter.com" target="_blank">
            {ReasonReact.string("twitter")}
            <Icon name=Feather.arrowRight color="#fff" />
          </a>
        </Chip>
      </Stage>
    )
  );
