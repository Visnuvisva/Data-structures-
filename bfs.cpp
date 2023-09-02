#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Queue structure for BFS
struct Queue {
    int data[MAX_VERTICES];
    int front;
    int rear;
};

// Function to initialize the queue
void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->rear == MAX_VERTICES - 1);
}

// Function to add an element to the queue
void enqueue(struct Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue element %d.\n", element);
        return;
    } else if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }

    queue->data[queue->rear] = element;
}

// Function to remove an element from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }

    int dequeuedElement = queue->data[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }

    return dequeuedElement;
}

// Function to perform Breadth First Search (BFS) on a graph
void BFS(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices, int source) {
    int visited[MAX_VERTICES] = {0};
    struct Queue queue;
    initQueue(&queue);

    // Mark the source vertex as visited and enqueue it
    visited[source] = 1;
    enqueue(&queue, source);

    printf("Breadth First Traversal (starting from vertex %d): ", source);

    while (!isEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);

        // Enqueue all adjacent vertices of the current vertex that are not visited yet
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(&queue, i);
            }
        }
    }

    printf("\n");
}

int main() {
    int numVertices, source;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    int adjMatrix[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("Enter the source vertex for BFS: ");
    scanf("%d", &source);

    BFS(adjMatrix, numVertices, source);

    return 0;
}

