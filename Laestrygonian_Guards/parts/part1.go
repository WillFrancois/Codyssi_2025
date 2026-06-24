package parts

import (
	"Laestrygonian_Guards/types"
	"maps"
	"slices"
)

func dfs (root *types.Node, n_map *map[string]*types.Node, d_map *map[string]int, running_distance int) {
	r := (*n_map)[root.Name]
	r.Visited = true
	val, ok := (*d_map)[r.Name]
	if !ok || running_distance < val {
		(*d_map)[r.Name] = running_distance
	}
	for i := range r.Connections {
		if (*n_map)[r.Connections[i]].Visited != true {
			dfs((*n_map)[r.Connections[i]], n_map, d_map, running_distance + 1)
		}
	}
	r.Visited = false
}

func dfs_weighted (root *types.Node, n_map *map[string]*types.Node, d_map *map[string]int, running_distance int) {
	r := (*n_map)[root.Name]
	r.Visited = true
	val, ok := (*d_map)[r.Name]
	if !ok || running_distance < val {
		(*d_map)[r.Name] = running_distance
	}
	for i := range r.Connections {
		if (*n_map)[r.Connections[i]].Visited != true {
			dfs_weighted((*n_map)[r.Connections[i]], n_map, d_map, running_distance + r.Distance[i])
		}
	}
	r.Visited = false
}

func Part1 (node_map map[string]*types.Node) int {
	distance_map := make(map[string]int, len(node_map))
	root := node_map["STT"]
	dfs(root, &node_map, &distance_map, 0)

	s := slices.Collect(maps.Values(distance_map))
	slices.Sort(s)
	slices.Reverse(s)
	return s[0] * s[1] * s[2]
}

func Part2 (node_map map[string]*types.Node) int {
	distance_map := make(map[string]int, len(node_map))
	root := node_map["STT"]
	dfs_weighted(root, &node_map, &distance_map, 0)

	s := slices.Collect(maps.Values(distance_map))
	slices.Sort(s)
	slices.Reverse(s)
	return s[0] * s[1] * s[2]
}
