type size =
  | ExtraSmall
  | Small
  | Medium
  | Large
  | ExtraLarge;

let fromLiteral = (size: string) =>
  switch (size) {
  | "xs" => ExtraSmall
  | "sm" => Small
  | "md" => Medium
  | "lg" => Large
  | "xl" => ExtraLarge
  | _ => Medium
  };

let toLiteral = (size: size) =>
  switch (size) {
  | ExtraSmall => "xs"
  | Small => "sm"
  | Medium => "md"
  | Large => "lg"
  | ExtraLarge => "xl"
  };

let fromNullableJsProps = (prop: Js.nullable(string)) =>
    Utils.fromNullableJsProps(prop, Medium, fromLiteral)
