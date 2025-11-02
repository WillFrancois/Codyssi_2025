package riskyshortcut

import (
	"regexp"
	"strings"
)

func Part2(x string) int {
	out := 0

	lines := strings.Split(x, "\n")

	// Prep input for part 1 again
	prep_re := regexp.MustCompile("[0-9][A-z\\-]|[A-z\\-][0-9]")

	for i := range lines {
		for prep_re.FindStringIndex(lines[i]) != nil {
			indices := prep_re.FindStringIndex(lines[i])
			lines[i] = lines[i][:indices[0]] + lines[i][indices[1]:]
		}
	}

	for _, line := range lines {
		out += len(line)
	}

	return out
}
