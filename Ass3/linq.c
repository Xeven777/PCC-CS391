#include <stdio.h>

#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} LinearQueue;

int isFull(LinearQueue* queue) {
    return (queue->rear == MAX_SIZE-1);
}

int isEmpty(LinearQueue* queue) {
    return (queue->front > queue->rear);
}

void enqueue(LinearQueue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
    } else {
        
        queue->rear++;
        queue->data[queue->rear] = data;
        printf("%d enqueued successfully.\n", data);
    }
}

int dequeue(LinearQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        int data = queue->data[queue->front];
        queue->front++;
        return data;
    }
}

void display(LinearQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        int i = queue->front;
        printf("Linear Queue: ");
        for(int i =queue->front;i<=queue->rear;i++)
        {
        	printf("%d\t", queue->data[i]);
        }
        printf("\n");
    }
}

int main() {
    LinearQueue queue;
    queue.front = 0;
    queue.rear = -1;

    int choice, data;
    do {
        printf("\nLinear Queue Operations\n");
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
