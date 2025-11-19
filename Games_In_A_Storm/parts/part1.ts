import { FileHandle } from "node:fs/promises";
import { FileValues } from "../main.ts";

export async function Part1(filehandle: FileHandle): Promise<number> {
  let max: number = 0;

  for await (const line of filehandle.readLines()) {
    let [num, base]: string[] = line.split(" ");
    let curr: number = 0;

    for (let i: number = 0; i < num.length; i++) {
      if (isNaN(+num[i])) {
        curr += FileValues[num[i]] * Math.pow(+base, num.length - i - 1);
      } else {
        curr += +num[i] * Math.pow(+base, num.length - i - 1);
      }
    }

    if (curr > max) {
      max = curr;
    }
    curr = 0;
  }

  return max;
}
