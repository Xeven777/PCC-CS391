#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MALLOC(p, s) p = malloc(sizeof(s))

typedef struct
{
    int value;
    struct node *next;
} node;

void insertAtFront(node **head, int x)
{
    node *new;
    MALLOC(new, sizeof(*new));
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
        temp = temp->next;
        if (degree > 0)
        {
            printf("x^%d + ", degree--);
        }
        else
        {
            printf("\n");
        }
    }
}

void main()
{
    node *head1, *head2, *head;
    head1 = NULL;
    head2 = NULL;
    head = NULL;

    int i, deg1, deg2, x;
    printf("Enter the degree of the first polynomial : ");
    scanf("%d", &deg1);
    for (i = 0; i <= deg1; i++)
    {
        if (i > 0)
        {
            printf("Enter the coefficient of x^%d : ", i);
            scanf("%d", &x);
        }
        else
        {
            printf("Enter the constant : ");
            scanf("%d", &x);
        }
        insertAtFront(&head1, x);
    }
    printf("Enter the degree of the second polynomial : ");
    scanf("%d", &deg2);
    for (i = 0; i <= deg2; i++)
    {
        if (i > 0)
        {
            printf("Enter the coefficient of x^%d : ", i);
            scanf("%d", &x);
        }
        else
        {
            printf("Enter the constant : ");
            scanf("%d", &x);
        }
        insertAtFront(&head2, x);
    }
    int deg = deg1 + deg2;
    for (i = 0; i <= deg; i++)
    {
        insertAtFront(&head, 0);
    }

    printf("Fisrt polynomial : ");
    display(head1, deg1);
    printf("Second polynomial : ");
    display(head2, deg2);

    int j, k, a, b, c;
    node *temp1, *temp2, *temp;
    temp1 = head1;
    for (i = 0; i <= deg1; i++)
    {
        temp2 = head2;
        a = temp1->value;
        for (j = 0; j <= deg2; j++)
        {
            temp = head;
            b = temp2->value;
            for (k = 0; k < i + j; k++)
            {
                temp = temp->next;
            }
            temp->value += a * b;
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    printf("Final result : ");
    display(head, deg);
}
