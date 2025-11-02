package main

import (
	"fmt"
	"os"
	"riskyshortcut/parts"
)

func main() {
	dat, err := os.ReadFile("./input.txt")
	if err != nil {
		panic(err)
	}

	fmt.Println(riskyshortcut.Part1(string(dat)))
	fmt.Println(riskyshortcut.Part2(string(dat)))
	fmt.Println(riskyshortcut.Part3(string(dat)))
}
