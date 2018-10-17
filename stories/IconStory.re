open BsStorybook.Story;

let _module = [%bs.raw "module"];

storiesOf("Icon", _module)
->(
    add("icon", () =>
      <Stage>
        <div>
          <p> {ReasonReact.string("feather")} </p>
          <Icon
            type_="feather"
            name="github"
            color="#498ff2"
            size="36"
            valign="middle"
          />
        </div>
        <div>
          <p> {ReasonReact.string("iconfont")} </p>
          <Icon
            type_="icon"
            name="angular"
            color="red"
            size="3em"
            valign="middle"
          />
        </div>
        <div>
          <p> {ReasonReact.string("ligature")} </p>
          <Icon
            ligature=true
            type_="material-icons"
            name="face"
            color="#212121"
            size="3em"
            valign="middle"
          />
        </div>
      </Stage>
    )
  )
->(
    add("feather icons", () => {
      let iconWrapperStyle =
        ReactDOMRe.Style.make(
          ~width="10%",
          ~marginBottom="1em",
          ~textAlign="center",
          (),
        );

      let icons =
        Array.mapi(
          (_, name) =>
            <div style=iconWrapperStyle key=name>
              <Icon name color="#afafaf" size="24" valign="middle" />
              <p> {ReasonReact.string(name)} </p>
            </div>,
          Feather.featherIcons,
        );

      let style =
        ReactDOMRe.Style.make(
          ~display="flex",
          ~flexWrap="wrap",
          ~padding="40px",
          (),
        );

      <Stage> <div style> {ReasonReact.array(icons)} </div> </Stage>;
    })
  );
