//Q4:Implement Dijsktra’s algorithm to compute the shortest path through a network

#include <stdio.h>

#define MAX 10
#define INF 9999

int main()
{
    int cost[MAX][MAX], dist[MAX], visited[MAX];
    int n, source, i, j, u, min;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    for(i = 0; i < n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    for(i = 1; i < n; i++)
    {
        min = INF;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && dist[u] + cost[u][j] < dist[j])
            {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for(i = 0; i < n; i++)
    {
        printf("To vertex %d = %d\n", i, dist[i]);
    }

    return 0;
}

/*
O/P:
Enter the number of vertices: 3
Enter the cost adjacency matrix:
1
4
3
4
0
0
3
5
2
Enter the source vertex: 1

Shortest distances from vertex 1:
To vertex 0 = 4
To vertex 1 = 0
To vertex 2 = 7
*/