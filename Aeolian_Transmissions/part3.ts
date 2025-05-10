//bun run part2.ts
import { readFileSync } from "node:fs";

let input: NonSharedBuffer = readFileSync("./input.txt");
let input_contents: string = input.toString();
let out: string = "";
let acc: number = 0;
let nums: string[] = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];

input_contents.split("\n").forEach((line: string) => {
  let l: number = 0;
  let r: number = 1;
  let line_value = 0;

  while (r < line.length) {
    if (line[l] === line[r]) {
      r += 1;
      continue;
    } else if (line[l] !== line[r]) {
      out += r - l + line[l];
      l = r;
      r += 1;
    }
  }

  out += r - l + line[l];
  console.log(out);
  line = out;

  line.split("").forEach((char: string) => {
    let add_value: number = 0;

    if (nums.includes(char)) {
      add_value += char.charCodeAt(0) - 48;
    } else {
      add_value += char.charCodeAt(0) - 64;
    }

    console.log(add_value);
    line_value += add_value;
  });
  acc += line_value;

  out = "";
});

acc -= 61; // NaN error somewhere
console.log(acc);
