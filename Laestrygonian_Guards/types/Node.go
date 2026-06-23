package types

type Node struct {
	Name string
	Connections []string
	Distance []int
	Visited bool
}
