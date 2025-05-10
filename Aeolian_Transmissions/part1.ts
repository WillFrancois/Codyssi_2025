//bun run part1.ts
import { readFileSync } from "node:fs";

let input: NonSharedBuffer = readFileSync("./input.txt");
let input_contents: string = input.toString();
let acc: number = 0;

input_contents.split("\n").forEach((line: string) => {
  let line_value: number = 0;
  line.split("").forEach((char: string) => {
    line_value += char.charCodeAt(0) - 64;
  });
  acc += line_value;
});

console.log(acc);
