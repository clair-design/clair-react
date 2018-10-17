const _ = require('lodash')
const { readdirSync, writeFileSync } = require('fs')
const files = readdirSync('./node_modules/react-feather/dist/icons/')
const keys = files.map(name => {
  name = name.replace('.js', '')
  if (name.toLowerCase() === 'type') name = 'typpe'
  return _.camelCase(name)
})

const ffi = keys
  .map(name => {
    let path = name.toLowerCase() === 'typpe' ? 'type' : name
    return `[@bs.module "react-feather/dist/icons/${_.kebabCase(path)}.js"]
external _${name}: ReasonReact.reactClass = "default";`
  })
  .join('\n')

const content = `${ffi}
let _iconMap = Js.Dict.empty();
let _component = ReasonReact.statelessComponent("FeatherNotFound");

${keys.map(name => `let ${name} = "${name}";`).join('\n')}
${keys.map(name => `Js.Dict.set(_iconMap, ${name}, _${name});`).join('\n')}

[@bs.deriving abstract]
type jsProps = {
  color: string,
  size: Js.nullable(string),
};

let featherIcons = Js.Dict.keys(_iconMap);

let make = (~name: string, ~color: string, ~size=?, _children) => {
  let wrap = myJSReactClass =>
    ReasonReact.wrapJsForReason(
      ~reactClass=myJSReactClass,
      ~props=jsProps(~color, ~size=Js.Nullable.fromOption(size)),
      _children,
    );

  switch (Js.Dict.get(_iconMap, name)) {
  | Some(jsReactClass) => wrap(jsReactClass)
  | None => {
    ..._component,
    render: _ => <em>{ReasonReact.string("FeatherNotFound")}</em>
  }
  }
}
`

const reiContent = `
${keys.map(name => `let ${name}: string;`).join('\n')}
let make: ( ~name: string, ~color: string, ~size: string = ?, 'a) => ReasonReact.component(
  ReasonReact.stateless,
  ReasonReact.noRetainedProps,
  ReasonReact.actionless
);

let featherIcons: array(string);
`

writeFileSync('./src/Feather.re', content)
writeFileSync('./src/Feather.rei', reiContent)
