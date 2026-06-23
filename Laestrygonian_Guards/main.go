package main

import (
	"fmt"
	"Laestrygonian_Guards/types"
	"os"
	"strconv"
	"strings"
)

func handleError(panout string) {
	panic(panout)
}

func main() {
	f, err := os.Open("input.txt")
	if (err != nil) {handleError("Could not open file")}
	stat, err := f.Stat()
	size := stat.Size()
	if (err != nil) {handleError("Could not get file size")}

	ba := make([]byte, size)
	f.Read(ba)
	input := string(ba)

	node_map := make(map[string]types.Node, strings.Count(input, "\n"))
	for line := range strings.Lines(input) {
		node_name := line[0:3]
		node_connection := line[7:10]
		path_value, err := strconv.Atoi(strings.Trim(strings.SplitAfterN(line, "| ", 2)[1], "\n"))
		if (err != nil) {handleError("Could not split string")}

		_, ok := node_map[node_name]
		if !ok {
			node_map[node_name] = types.Node{Name: node_name}
		}
		_, ok = node_map[node_connection]
		if !ok {
			node_map[node_connection] = types.Node{Name: node_name}
		}

		a := node_map[node_name]
		b := node_map[node_connection]

		a.Connections = append(a.Connections, &b)
		a.Distance = append(a.Distance, path_value)
		node_map[node_name] = a
	}

	fmt.Println(node_map)
}
