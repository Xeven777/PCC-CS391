#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void dfs(int start, int vertices, int graph[MAX][MAX], int visited[MAX])
{
    visited[start] = 1;
    printf("%d ->", start);

    for (int i = 0; i < vertices; i++)
    {
        if (graph[start][i] == 1 && visited[i] != 1)
        {
            dfs(i, vertices, graph, visited);
        }
    }
}

int main()
{
    int graph[MAX][MAX] = {0}; // Adjacency matrix
    int visited[MAX] = {0};    // Visited array
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
    printf("Enter the start vertex: ");
    scanf("%d", &start);
    dfs(start, vertices, graph, visited);
    return 0;
}
