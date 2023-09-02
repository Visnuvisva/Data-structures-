#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[], int numVertices) {
    int min = INT_MAX, minVertex;

    for (int v = 0; v < numVertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minVertex = v;
        }
    }

    return minVertex;
}

// Function to print the shortest path from source to target
void printPath(int parent[], int target) {
    if (parent[target] == -1)
        return;

    printPath(parent, parent[target]);
    printf(" -> %d", target);
}

// Function to perform Dijkstra's algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int source) {
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int parent[MAX_VERTICES];

    // Initialize distance, visited, and parent arrays
    for (int i = 0; i < numVertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    // Distance from source to itself is always 0
    dist[source] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance(dist, visited, numVertices);

        visited[u] = 1;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Shortest paths from source vertex %d:\n", source);
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: Distance = %d, Path = %d", i, dist[i], source);
        printPath(parent, i);
        printf("\n");
    }
}

int main() {
    int numVertices, source;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, numVertices, source);

    return 0;
}

