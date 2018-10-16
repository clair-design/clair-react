/* SEE https://github.com/MyWellGiving/bs-storybook */
open BsStorybook.Story;

let _module = [%bs.raw "module"];

let flat = true;
let primary = true;
let success = true;
let warning = true;
let danger = true;
let outline = true;
let round = true;
let disabled = true;
let loading = true;

storiesOf("Icon", _module)
->(
    add("TODO", () =>
      <Stage>
        <p>
          <Button> {ReasonReact.string({j|默认按钮|j})} </Button>
          <Button round> {ReasonReact.string({j|圆角风格|j})} </Button>
          <Button outline> {ReasonReact.string({j|线框风格|j})} </Button>
          <Button outline round>
            {ReasonReact.string({j|圆角线框|j})}
          </Button>
          <Button flat> {ReasonReact.string({j|扁平按钮|j})} </Button>
        </p>
        <p>
          <Button primary> {ReasonReact.string({j|主要操作|j})} </Button>
          <Button primary round>
            {ReasonReact.string({j|圆角风格|j})}
          </Button>
          <Button primary outline>
            {ReasonReact.string({j|线框风格|j})}
          </Button>
          <Button primary outline round>
            {ReasonReact.string({j|圆角线框|j})}
          </Button>
          <Button primary flat>
            {ReasonReact.string({j|扁平按钮|j})}
          </Button>
        </p>
        <p>
          <Button success> {ReasonReact.string({j|正向操作|j})} </Button>
          <Button success round>
            {ReasonReact.string({j|圆角风格|j})}
          </Button>
          <Button success outline>
            {ReasonReact.string({j|线框风格|j})}
          </Button>
          <Button success outline round>
            {ReasonReact.string({j|圆角线框|j})}
          </Button>
          <Button success flat>
            {ReasonReact.string({j|扁平按钮|j})}
          </Button>
        </p>
        <p>
          <Button warning> {ReasonReact.string({j|警告操作|j})} </Button>
          <Button warning round>
            {ReasonReact.string({j|圆角风格|j})}
          </Button>
          <Button warning outline>
            {ReasonReact.string({j|线框风格|j})}
          </Button>
          <Button warning outline round>
            {ReasonReact.string({j|圆角线框|j})}
          </Button>
          <Button warning flat>
            {ReasonReact.string({j|扁平按钮|j})}
          </Button>
        </p>
        <p>
          <Button danger> {ReasonReact.string({j|危险操作|j})} </Button>
          <Button danger round>
            {ReasonReact.string({j|圆角风格|j})}
          </Button>
          <Button danger outline>
            {ReasonReact.string({j|线框风格|j})}
          </Button>
          <Button danger outline round>
            {ReasonReact.string({j|圆角线框|j})}
          </Button>
          <Button danger flat>
            {ReasonReact.string({j|扁平按钮|j})}
          </Button>
        </p>
      </Stage>
    )
  )
