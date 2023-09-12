#include <stdio.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} CircularQueue;

int isFull(CircularQueue* queue) {
    return ((queue->front == 0 && queue->rear == MAX_SIZE - 1) || (queue->front == queue->rear + 1));
}

int isEmpty(CircularQueue* queue) {
    return (queue->front == -1);
}

void enqueue(CircularQueue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->data[queue->rear] = data;
        printf("%d enqueued successfully.\n", data);
    }
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        int data = queue->data[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return data;
    }
}

void display(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        int i = queue->front;
        printf("Circular Queue: ");
        do {
            printf("%d ", queue->data[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (queue->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    CircularQueue queue;
    queue.front = -1;
    queue.rear = -1;

    int choice, data;
    do {
        printf("\nCircular Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                data = dequeue(&queue);
                if (data != -1) {
                    printf("%d dequeued successfully.\n", data);
                }
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
