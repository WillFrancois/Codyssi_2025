import { FileHandle } from "node:fs/promises";
import { FileValues, revVal } from "../main.ts";

export async function Part2(filehandle: FileHandle): Promise<string> {
  const convBase = 68;
  let out: string = "";
  let sum: number = 0;

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

    sum += curr;
    curr = 0;
  }

  while (sum > 0) {
    out = revVal[Math.floor(sum % convBase)] + out;
    sum = Math.floor(sum / convBase);
  }

  return out;
}
