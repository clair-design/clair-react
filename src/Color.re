type color =
  | Red
  | Orange
  | Yellow
  | Green
  | Cyan
  | Blue
  | Indigo
  | Purple
  | Pink
  | Dark
  | Black
  | Color(string);

let fromLiteral = (color: string) =>
  switch (color) {
  | "red" => Red
  | "orange" => Orange
  | "yellow" => Yellow
  | "green" => Green
  | "cyan" => Cyan
  | "blue" => Blue
  | "indigo" => Indigo
  | "purple" => Purple
  | "pink" => Pink
  | "dark" => Dark
  | "black" => Black
  | str => Color(str)
  };

let toLiteral = (color: color) =>
  switch (color) {
  | Red => "red"
  | Orange => "orange"
  | Yellow => "yellow"
  | Green => "green"
  | Cyan => "cyan"
  | Blue => "blue"
  | Indigo => "indigo"
  | Purple => "purple"
  | Pink => "pink"
  | Dark => "dark"
  | Black => "black"
  | Color(str) => str
  };

let isPresetColor = (color: color) =>
  switch (color) {
  | Red
  | Orange
  | Yellow
  | Green
  | Cyan
  | Blue
  | Indigo
  | Purple
  | Pink
  | Dark
  | Black => true
  | _ => false
  };

let presetColors = [|
  Red,
  Orange,
  Yellow,
  Green,
  Cyan,
  Blue,
  Indigo,
  Purple,
  Pink,
  Dark,
  Black,
|];

let fromNullableJsProps = (prop: Js.nullable(string)) =>
  Utils.fromNullableJsProps(prop, Color(""), fromLiteral)
