# Count Complete Connected Components

## Problem Statement

You are given an integer `n`. There is an undirected graph with `n` vertices, numbered from `0` to `n - 1`. You are given a 2D integer array `edges` where `edges[i] = [ai, bi]` denotes that there exists an undirected edge connecting vertices `ai` and `bi`.

Return the number of complete connected components of the graph.

A **connected component** is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be **complete** if there exists an edge between every pair of its vertices.

---

## Constraints:

- `1 <= n <= 50`
- `0 <= edges.length <= n * (n - 1) / 2`
- `edges[i].length == 2`
- `0 <= ai, bi <= n - 1`
- `ai != bi`
- There are no repeated edges.

---

## Approach

1. **Graph Representation:**  
   - Use an adjacency list (`vector<int> adj[n]`) to store the graph.
   - Store all edges bidirectionally since the graph is undirected.

2. **Finding Connected Components:**  
   - Use DFS or BFS to traverse the graph and find all connected components.

3. **Checking for Complete Components:**  
   - A connected component with `m` nodes is **complete** if it contains exactly `m * (m - 1) / 2` edges.
