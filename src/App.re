open Utils;

requireCSS("./App.css");

let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self => {
    let flat = true;
    let primary = true;
    let success = true;
    let warning = true;
    let danger = true;
    let outline = true;
    let round = true;

    <div className="App">
      <p>
        <Icon
          type_="feather"
          name="github"
          color="#498ff2"
          size="36"
          valign="middle"
        />
        <Icon
          type_="icon"
          name="angular"
          color="red"
          size="3em"
          valign="middle"
        />
        <Icon
          type_="icon"
          name="reactjs"
          color="blue"
          size="3em"
          valign="middle"
        />
        <Icon
          ligature=true
          type_="material-icons"
          name="face"
          color="#212121"
          size="3em"
          valign="middle"
        />
      </p>
      <Breadcrumb>
        <Breadcrumb.Item>
          <a href="#"> {ReasonReact.string("Home")} </a>
        </Breadcrumb.Item>
        <Breadcrumb.Item>
          <a href="#"> {ReasonReact.string("Info")} </a>
        </Breadcrumb.Item>
        <Breadcrumb.Item> {ReasonReact.string("Detail")} </Breadcrumb.Item>
      </Breadcrumb>
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
        <Button danger loading=true size=XL autofocus=true>
          {ReasonReact.string({j|危险操作|j})}
        </Button>
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
        <Button danger flat href="/baidu/com">
          {ReasonReact.string({j|扁平按钮|j})}
        </Button>
      </p>
    </div>;
  },
};
