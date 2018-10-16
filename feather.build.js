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
external ${name}: ReasonReact.reactClass = "default";`
  })
  .join('\n')

const content = `${ffi}
let featherNotFound = ReasonReact.statelessComponent("FeatherNotFound");

[@bs.deriving abstract]
type jsProps = {
  color: string,
  size: Js.nullable(string),
};

let make = (~name: string, ~color: string, ~size=?, _children) => {
  let wrap = myJSReactClass =>
    ReasonReact.wrapJsForReason(
      ~reactClass=myJSReactClass,
      ~props=jsProps(~color, ~size=Js.Nullable.fromOption(size)),
      _children,
    );
  switch (name) {
${keys.map(name => `  | "${name}" => wrap(${name})`).join('\n')}
  | _ => {
    ...featherNotFound,
    render: _ => <em>{ReasonReact.string("FeatherNotFound")}</em>
  }
  }
}
`

writeFileSync('./src/Feather.re', content)
