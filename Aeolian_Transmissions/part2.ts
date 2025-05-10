//bun run part2.ts
import { readFileSync } from "node:fs";

let input: NonSharedBuffer = readFileSync("./input.txt");
let input_contents: string = input.toString();
let acc: number = 0;
let nums: string[] = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"];

input_contents.split("\n").forEach((line: string) => {
  let line_value: number = 0;

  let lt_char_length = Math.floor(line.length / 10);
  line =
    line.substring(0, lt_char_length) +
    line.substring(lt_char_length, line.length - lt_char_length).length +
    line.substring(line.length - lt_char_length, line.length);

  console.log(line);

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
});

console.log(acc);
