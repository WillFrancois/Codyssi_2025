package windybargain

import (
	// "fmt"
	"sort"
	"strconv"
	"strings"
)

func Part2(x []string) int {
	states := strings.Split(x[0], "\n")
	transactions := strings.Split(x[1], "\n")
	money_map := make(map[string]int, len(states))

	for i := range states {
		words := strings.Split(states[i], " ")
		money_map[words[0]], _ = strconv.Atoi(words[2])
	}

	for i := 0; i < len(transactions)-1; i++ {
		words := strings.Split(transactions[i], " ")

		f := words[1]
		t := words[3]
		amount, _ := strconv.Atoi(words[5])

		if money_map[f] > amount {
			money_map[t] += amount
			money_map[f] -= amount
		} else {
			money_map[t] += money_map[f]
			money_map[f] = 0
		}
	}

	var values []int
	for _, v := range money_map {
		values = append(values, v)
	}
	sort.Slice(values, func(i, j int) bool {
		return values[i] > values[j]
	})

	return values[0] + values[1] + values[2]
}
