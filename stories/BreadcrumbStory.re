open BsStorybook.Story;

let _module = [%bs.raw "module"];

storiesOf("Breadcrumb", _module)
->(
    add("breadcrumb", () =>
      <Stage>
        <Breadcrumb>
          <Breadcrumb.Item>
            <a> {ReasonReact.string("Home")} </a>
          </Breadcrumb.Item>
          <Breadcrumb.Item>
            <a> {ReasonReact.string("Info")} </a>
          </Breadcrumb.Item>
          <Breadcrumb.Item> {ReasonReact.string("Detail")} </Breadcrumb.Item>
        </Breadcrumb>
        <Breadcrumb divider="|">
          <Breadcrumb.Item>
            <a> {ReasonReact.string("Home")} </a>
          </Breadcrumb.Item>
          <Breadcrumb.Item>
            <a> {ReasonReact.string("Info")} </a>
          </Breadcrumb.Item>
          <Breadcrumb.Item> {ReasonReact.string("Detail")} </Breadcrumb.Item>
        </Breadcrumb>
      </Stage>
    )
  );
