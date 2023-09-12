#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    int value;
    struct node *next;
} node;

void insertAtFirst(node **head, int x)
{
    node *new = (node *)malloc(sizeof(node));
    new->value = x;
    new->next = (*head);
    (*head) = new;
}

void display(node *head, int degree)
{
    node *temp;
    temp = head;
    while (temp)
    {
        printf("(%d)", temp->value);
        if (degree > 0)
        {
            printf("x^%d + ", degree--);
        }
        else
        {
            printf("\n");
        }
        temp = temp->next;
    }
}

void main()
{
    node *head1, *head2, *head;
    head1 = NULL;
    head2 = NULL;
    head = NULL;
    int deg1, deg2, i, x;
    printf("Enter the degree of the first polynomial : ");
    scanf("%d", &deg1);
    for (i = 0; i <= deg1; i++)
    {
        if (i > 0)
        {
            printf("Enter the coefficient of x^%d : ", i);
        }
        else
        {
            printf("Enter the constant : ");
        }
        scanf("%d", &x);
        insertAtFirst(&head1, x);
    }
    printf("Enter the degree of the second polynomial : ");
    scanf("%d", &deg2);
    for (i = 0; i <= deg2; i++)
    {
        printf("Enter the coefficient of x^%d : ", i);
        scanf("%d", &x);
        insertAtFirst(&head2, x);
    }

    printf("First polynomial : ");
    display(head1, deg1);
    printf("Second polynomial : ");
    display(head2, deg2);

    if (deg1 < deg2)
    {
        int temp;
        temp = deg1;
        deg1 = deg2;
        deg2 = temp;
        node *t;
        t = head1;
        head1 = head2;
        head2 = t;
    }
    for (i = 0; i <= deg1; i++)
    {
        insertAtFirst(&head, 0);
    }

    node *temp, *temp1, *temp2;
    temp1 = head1;
    temp2 = head2;
    temp = head;
    for (i = 0; i <= deg1; i++)
    {
        if (i >= deg1 - deg2)
        {
            temp->value += temp1->value + temp2->value;
            if (i < deg1)
            {
                temp = temp->next;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        else
        {
            temp->value += temp1->value;
            if (i < deg1)
            {
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
    }

    printf("Final result : ");
    display(head, deg1);
}
