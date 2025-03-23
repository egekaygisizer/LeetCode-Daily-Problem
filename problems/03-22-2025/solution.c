#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 50

typedef struct {
    int edges[MAX_NODES];
    int size;
} AdjList;

void dfs(int node, AdjList* graph, bool* visited, int* nodes, int* edges) {
    visited[node] = true;
    (*nodes)++; 

    for (int i = 0; i < graph[node].size; i++) {
        (*edges)++; 
        int neighbor = graph[node].edges[i];
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, nodes, edges);
        }
    }
}

int countCompleteComponents(int n, int edgesArray[][2], int edgesSize) {
    AdjList graph[MAX_NODES] = {0};
    bool visited[MAX_NODES] = {false};

    for (int i = 0; i < edgesSize; i++) {
        int u = edgesArray[i][0], v = edgesArray[i][1];
        graph[u].edges[graph[u].size++] = v;
        graph[v].edges[graph[v].size++] = u;
    }

    int completeComponents = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int nodes = 0, edges = 0;
            dfs(i, graph, visited, &nodes, &edges);
            edges /= 2; 

            if (edges == (nodes * (nodes - 1)) / 2) {
                completeComponents++;
            }
        }
    }

    return completeComponents;
}

int main() {
    int edges1[][2] = {{0,1}, {0,2}, {1,2}, {3,4}};
    printf("%d\n", countCompleteComponents(6, edges1, 4)); 

    int edges2[][2] = {{0,1}, {0,2}, {1,2}, {3,4}, {3,5}};
    printf("%d\n", countCompleteComponents(6, edges2, 5)); 

    return 0;
}