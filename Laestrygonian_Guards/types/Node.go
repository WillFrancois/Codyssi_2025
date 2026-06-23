package types

type Node struct {
	Name string
	Connections []*Node
	Distance []int
	Visited bool
}
