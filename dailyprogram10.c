#include <stdio.h>

#define MAX 100  

int adjacencyMatrix[MAX][MAX]; 
int visited[MAX];  
int nodes;  

void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;  

    for (int i = 0; i < nodes; i++) {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, src, dest;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &nodes, &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            adjacencyMatrix[i][j] = 0;
        }
        visited[i] = 0;
    }

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        adjacencyMatrix[src][dest] = 1;
        adjacencyMatrix[dest][src] = 1;  // For an undirected graph
    }

    printf("DFS Traversal starting from node 0: ");
    DFS(0);

    return 0;
}
