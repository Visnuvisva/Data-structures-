#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Queue structure
struct Queue {
    int data[MAX_SIZE];
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
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Function to add an element to the queue (ENQUEUE)
void enqueue(struct Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue Overflow: Cannot enqueue element %d, queue is full.\n", element);
        return;
    } else if (isEmpty(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->data[queue->rear] = element;
    printf("Element %d enqueued to the queue.\n", element);
}

// Function to remove an element from the queue (DEQUEUE)
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow: Cannot dequeue element, queue is empty.\n");
        return -1;
    }

    int dequeuedElement = queue->data[queue->front];

    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    return dequeuedElement;
}

// Function to display the elements in the queue
void displayQueue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }

    printf("Queue: ");
    int i = queue->front;
    do {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);

    printf("\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    displayQueue(&queue);

    int dequeuedElement = dequeue(&queue);
    if (dequeuedElement != -1) {
        printf("Dequeued element: %d\n", dequeuedElement);
    }

    displayQueue(&queue);

    return 0;
}

