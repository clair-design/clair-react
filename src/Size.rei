type size =
  | ExtraSmall
  | Small
  | Medium
  | Large
  | ExtraLarge;
let fromLiteral: string => size;
let toLiteral: size => string;
let fromNullableJsProps: Js.nullable(string) => size;
