#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct queue
{
    int items[MAX];
    int front;
    int rear;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

void enqueue(Queue *q, int n)
{
    if (q->rear == MAX - 1)
        printf("full");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = n;
    }
}

int dequeue(Queue *q)
{
    int num;
    if (q->rear == -1)
    {
        num = -1;
        printf("Queue empty");
    }
    else
    {
        num = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }
    return num;
}

void bfs(int graph[MAX][MAX], int start, int vertices)
{
    int visited[MAX] = {0};
    Queue *queue = createQueue();
    visited[start] = 1;
    printf("starting from %d ->", start);
    enqueue(queue, start);
    while (queue->rear != -1)
    {
        int currentVertex = dequeue(queue);
        for (int i = 0; i <= vertices; i++)
        {
            if (graph[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                printf("%d ->", i);
                enqueue(queue, i);
            }
        }
    }
}

void main()
{
    int graph[MAX][MAX] = {0}; // Adjacency matrix
    int vertices, edges;
    printf("Enter the number of vertices & edges: ");
    scanf("%d %d", &vertices, &edges);
    for (int i = 0; i < edges; i++)
    {
        int x, y;
        printf("Enter the vertices: ");
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    int start;
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    bfs(graph, start, vertices);
}
