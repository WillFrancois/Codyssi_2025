package riskyshortcut

import (
	"regexp"
	"strings"
)

func Part1(x string) int {
	out := 0

	lines := strings.Split(x, "\n")

	for _, line := range lines {
		re := regexp.MustCompile("[A-z]")
		out += len(re.FindAllString(line, -1))
	}

	return out
}
