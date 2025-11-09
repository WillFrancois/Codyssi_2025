package windybargain

import (
	"math"
	"sort"
	"strconv"
	"strings"
)

type Debt struct {
	name   string
	amount int
}

func Part3(x []string) int {
	states := strings.Split(x[0], "\n")
	transactions := strings.Split(x[1], "\n")
	money_map := make(map[string]int, len(states))
	debt_map := make(map[string][]Debt)

	for i := range states {
		words := strings.Split(states[i], " ")
		money_map[words[0]], _ = strconv.Atoi(words[2])
	}

	for i := 0; i < len(transactions)-1; i++ {
		words := strings.Split(transactions[i], " ")

		// Break transactions into data
		f := words[1]
		t := words[3]
		amount, _ := strconv.Atoi(words[5])

		// Handle initial payments
		if money_map[f] >= amount {
			money_map[t] += amount
			money_map[f] -= amount
		} else {
			debt_map[f] = append(debt_map[f], Debt{name: t, amount: -(money_map[f] - amount)})
			money_map[t] += money_map[f]
			money_map[f] = 0
		}

		// Handle debt payments
		for k, _ := range money_map {
			for len(debt_map[k]) > 0 {
				if money_map[k] < 0 {
					return 0
				}
				// Find minimum value
				mov := int(math.Min(float64(money_map[k]), float64(debt_map[k][0].amount)))
				// Remove money from user
				money_map[k] -= mov
				// Add money to owner of debt
				money_map[debt_map[k][0].name] += mov
				// Remove debt
				debt_map[k][0].amount -= mov

				// Remove debt if amount is 0
				if debt_map[k][0].amount <= 0 {
					if len(debt_map[k]) > 1 {
						debt_map[k] = debt_map[k][1:]
					} else {
						debt_map[k] = []Debt{}
						break
					}
				}

				// User can no longer pay debt
				if money_map[k] == 0 {
					break
				}
			}
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
