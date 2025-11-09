package main

import (
	"fmt"
	"os"
	"strings"
	"windybargain/parts"
)

func main() {
	dat, err := os.ReadFile("input.txt")
	if err != nil {
		panic(err)
	}

	content := strings.Split(string(dat), "\n\n")

	fmt.Println(windybargain.Part1(content))
	fmt.Println(windybargain.Part2(content))
	fmt.Println(windybargain.Part3(content))
}
