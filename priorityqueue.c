#include <stdio.h>
#include <stdlib.h>
typedef struct Pnode
{
    int data;
    int priority;
    struct Pnode *next;
} Node;

Node *createNode(int data, int priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.");
        return NULL;
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int data, int priority, Node **front)
{
    Node *newNode = createNode(data, priority);
    if (*front == NULL || priority < (*front)->priority)
    {
        newNode->next = *front;
        *front = newNode;
    }
    else
    {
        Node *temp = *front;
        while (temp->next != NULL && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int dequeue(Node **front)
{
    if (*front == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    Node *temp = *front;
    *front = (*front)->next;
    int data = temp->data;
    free(temp);
    return data;
}

int isEmpty(Node *front)
{
    return (front == NULL);
}

int main()
{
    Node *front = NULL;
    int choice, data, priority,i;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data and priority: ");
            scanf("%d %d", &data, &priority);
            enqueue(data, priority, &front);
            break;
        case 2:
            printf("Dequeued element is: %d\n", dequeue(&front));
            break;
        case 3:
            if (isEmpty(front))
                printf("Queue is empty.\n");
            else
                printf("Queue is not empty.\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

}
