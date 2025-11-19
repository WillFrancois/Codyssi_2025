import { Part1 } from "./parts/part1.ts";
import { Part2 } from "./parts/part2.ts";
import { FileHandle, open } from "node:fs/promises";

export enum FileValues {
  "A" = 10,
  "B",
  "C",
  "D",
  "E",
  "F",
  "G",
  "H",
  "I",
  "J",
  "K",
  "L",
  "M",
  "N",
  "O",
  "P",
  "Q",
  "R",
  "S",
  "T",
  "U",
  "V",
  "W",
  "X",
  "Y",
  "Z",
  "a",
  "b",
  "c",
  "d",
  "e",
  "f",
  "g",
  "h",
  "i",
  "j",
  "k",
  "l",
  "m",
  "n",
  "o",
  "p",
  "q",
  "r",
  "s",
  "t",
  "u",
  "v",
  "w",
  "x",
  "y",
  "z",
}

let filehandle: FileHandle = await open("input.txt", "r");

async function main(): Promise<void> {
  console.log(await Part1(filehandle));
  console.log(await Part2(filehandle));
}

main();
