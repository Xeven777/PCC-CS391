#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    int queue[MAX];
    int front, rear;
} DQueue;

void initialize(DQueue *dQueue)
{
    dQueue->front = -1;
    dQueue->rear = -1;
}

void insertFront(DQueue *dQueue)
{
    int item = 0;
    if ((dQueue->front == 0 && dQueue->rear == MAX - 1) || (dQueue->front == dQueue->rear + 1))
    {
        printf("QUEUE OVERFLOW!\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &item);
    if (dQueue->front == -1)
    {
        dQueue->front = 0;
        dQueue->rear = 0;
    }
    else
    {
        if (dQueue->front == 0)
            dQueue->front = MAX - 1;
        else
            dQueue->front = dQueue->front - 1;
    }
    dQueue->queue[dQueue->front] = item;
}

void insertRear(DQueue *dQueue)
{
    int item = 0;
    if ((dQueue->front == 0 && dQueue->rear == MAX - 1) || (dQueue->front == dQueue->rear + 1))
    {
        printf("QUEUE OVERFLOW!\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &item);
    if (dQueue->front == -1)
    {
        dQueue->front = 0;
        dQueue->rear = 0;
    }
    else
    {
        if (dQueue->rear == MAX - 1)
            dQueue->rear = 0;
        else
            dQueue->rear = dQueue->rear + 1;
    }
    dQueue->queue[dQueue->rear] = item;
}

int deleteFront(DQueue *dQueue)
{
    int item = 0;
    if (dQueue->front == -1)
    {
        printf("QUEUE UNDERFLOW!\n");
        exit(1);
    }
    item = dQueue->queue[dQueue->front];
    if (dQueue->front == dQueue->rear)
    {
        dQueue->front = -1;
        dQueue->rear = -1;
    }
    else
    {
        if (dQueue->front == MAX - 1)
            dQueue->front = 0;
        else
            dQueue->front = dQueue->front + 1;
    }
    return item;
}

int deleteRear(DQueue *dQueue)
{
    int item = 0;
    if (dQueue->front == -1)
    {
        printf("QUEUE UNDERFLOW!\n");
        exit(1);
    }
    item = dQueue->queue[dQueue->rear];
    if (dQueue->front == dQueue->rear)
    {
        dQueue->front = -1;
        dQueue->rear = -1;
    }
    else
    {
        if (dQueue->rear == 0)
            dQueue->rear = MAX - 1;
        else
            dQueue->rear = dQueue->rear - 1;
    }
    return item;
}

void display(DQueue *dQueue)
{
    int i = 0;
    if (dQueue->front == -1)
    {
        printf("QUEUE IS EMPTY!\n");
        return;
    }
    printf("QUEUE ELEMENTS:\n");
    if (dQueue->front <= dQueue->rear)
    {
        for (i = dQueue->front; i <= dQueue->rear; i++)
            printf("%d\t", dQueue->queue[i]);
    }
    else
    {
        for (i = dQueue->front; i < MAX; i++)
            printf("%d\t", dQueue->queue[i]);
        for (i = 0; i <= dQueue->rear; i++)
            printf("%d\t", dQueue->queue[i]);
    }
    printf("\n");
}

int main()
{
    DQueue dQueue;
    initialize(&dQueue);

    int choice = 0, item = 0;
    while (1)
    {
        printf("1-> Insert at front\n");
        printf("2-> Insert at rear\n");
        printf("3-> Delete from front\n");
        printf("4-> Delete from rear\n");
        printf("5-> Display\n");
        printf("6-> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertFront(&dQueue);
            break;
        case 2:
            insertRear(&dQueue);
            break;
        case 3:
            item = deleteFront(&dQueue);
            printf("Deleted item: %d\n", item);
            break;
        case 4:
            item = deleteRear(&dQueue);
            printf("Deleted item: %d\n", item);
            break;
        case 5:
            display(&dQueue);
            break;
        case 6:
            exit(0);
        default:
            printf("INVALID CHOICE!\n");
        }
    }
    return 0;
}
