import { FileHandle } from "node:fs/promises";
import { FileValues } from "../main.ts";

export async function Part3(filehandle: FileHandle): Promise<number> {
  let sum: number = 0;

  for await (const line of filehandle.readLines()) {
    const [num, base]: string[] = line.split(" ");
    let curr: number = 0;

    for (let i: number = 0; i < num.length; i++) {
      if (isNaN(+num[i])) {
        // @ts-ignore FileValues will always reference a number. Method of indexing is not recommended in TS.
        curr += FileValues[num[i]] * Math.pow(+base, num.length - i - 1);
      } else {
        curr += +num[i] * Math.pow(+base, num.length - i - 1);
      }
    }

    sum += curr;
    curr = 0;
  }

  let x = 10;
  while (true) {
    let test = 0;
    for (let i: number = 0; i < 4; i++) {
      test += Math.pow(x, i) * (x - 1);
    }
    if (test > sum) {
      return x;
    }
    x += 1;
  }
}
