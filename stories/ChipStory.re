open BsStorybook.Story;

let _module = [%bs.raw "module"];
[@bs.val] external alert: string => unit = "alert";

let onClose = e => Js.log(e);
let lists = Color.presetColors;
let arr =
  Array.map(
    color =>
      <Chip
        label={Color.toLiteral(color)}
        color
        key={Color.toLiteral(color)}
        onClose
      />,
    lists,
  );

storiesOf("Chip", _module)
->(add("chip", () => <Stage> {ReasonReact.array(arr)} </Stage>))
->(
    add("size", () =>
      <Stage>
        <Chip label="small" size=Size.Small />
        <Chip label="normal" size=Size.Medium />
      </Stage>
    )
  )
->(
    add("close event", () =>
      <Stage>
        <Chip
          color=Color.Purple
          closable=true
          label="closea chip"
          onClose={_ => alert("Close")}
        />
      </Stage>
    )
  )
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
            <Icon name=Feather.twitter color="#fff" />
          </a>
          {ReasonReact.string("  twitter")}
        </Chip>
      </Stage>
    )
  );
