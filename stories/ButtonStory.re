/* SEE https://github.com/MyWellGiving/bs-storybook */
open BsStorybook.Story;

let _module = [%bs.raw "module"];
[@bs.val] external alert : string => unit = "alert";

let flat = true;
let primary = true;
let success = true;
let warning = true;
let danger = true;
let outline = true;
let round = true;
let disabled = true;
let loading = true;

storiesOf("Button", _module)
->(
    add("styles", () =>
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
->(
    add("disabled", () =>
      <Stage>
        <Button disabled> {ReasonReact.string({j|普通按钮|j})} </Button>
        <Button disabled outline>
          {ReasonReact.string({j|线框按钮|j})}
        </Button>
        <Button primary disabled>
          {ReasonReact.string({j|主操作按钮|j})}
        </Button>
        <Button primary disabled outline>
          {ReasonReact.string({j|线框主操作按钮|j})}
        </Button>
        <Button danger disabled>
          {ReasonReact.string({j|危险按钮|j})}
        </Button>
        <Button danger disabled outline>
          {ReasonReact.string({j|危险线框|j})}
        </Button>
        <Button disabled flat>
          {ReasonReact.string({j|扁平按钮|j})}
        </Button>
      </Stage>
    )
  )
->(
    add("size", () =>
      <Stage>
        <Button primary size=Size.ExtraSmall>
          {ReasonReact.string({j|超小按钮|j})}
        </Button>
        <Button primary size=Size.Small>
          {ReasonReact.string({j|小号按钮|j})}
        </Button>
        <Button primary> {ReasonReact.string({j|普通按钮|j})} </Button>
        <Button primary outline size=Size.Large>
          {ReasonReact.string({j|大号按钮|j})}
        </Button>
        <Button primary outline size=Size.ExtraLarge>
          {ReasonReact.string({j|超大号按钮|j})}
        </Button>
      </Stage>
    )
  )
->(
    add("loading", () =>
      <Stage>
        <Button loading> {ReasonReact.string({j|加载中|j})} </Button>
        <Button loading primary outline round>
          {ReasonReact.string({j|正在提交|j})}
        </Button>
        <Button danger loading flat>
          {ReasonReact.string({j|正在删除|j})}
        </Button>
      </Stage>
    )
  )
->(
    add("group", () =>
      <Stage>
        <Button.Group size=Size.ExtraSmall>
          <Button> {ReasonReact.string({j|加粗|j})} </Button>
          <Button> {ReasonReact.string({j|斜体|j})} </Button>
          <Button> {ReasonReact.string({j|下划线|j})} </Button>
        </Button.Group>
        <Button.Group size=Size.Small>
          <Button outline icon="twitter" />
          <Button outline icon="facebook" />
          <Button outline icon="github" />
        </Button.Group>
        <Button.Group>
          <Button primary icon="bold" />
          <Button primary icon="italic" />
          <Button primary icon="repeat" />
        </Button.Group>
        <Button.Group>
          <Button primary outline> {ReasonReact.string("A")} </Button>
          <Button primary outline> {ReasonReact.string("B")} </Button>
          <Button primary outline> {ReasonReact.string("C")} </Button>
        </Button.Group>
        <Button.Group size=Size.Large>
          <Button danger> {ReasonReact.string("A")} </Button>
          <Button danger> {ReasonReact.string("B")} </Button>
          <Button danger> {ReasonReact.string("C")} </Button>
        </Button.Group>
        <Button.Group size=Size.ExtraLarge>
          <Button danger outline> {ReasonReact.string("A")} </Button>
          <Button danger outline> {ReasonReact.string("B")} </Button>
          <Button danger outline> {ReasonReact.string("C")} </Button>
        </Button.Group>
      </Stage>
    )
  )
->(
    add("event", () =>
      <Stage>
        <Button primary outline icon="heart" onClick={_ => alert("Clicked")} />
      </Stage>
    )
  )
