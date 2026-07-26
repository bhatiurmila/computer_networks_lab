//Q6:Implement distance vector routing algorithm for obtaining 
//routing tables at each node. 

#include <stdio.h>

#define MAX 10
#define INF 9999

int main()
{
    int cost[MAX][MAX], dist[MAX][MAX];
    int n, i, j, k;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INF;

            dist[i][j] = cost[i][j];
        }
    }

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nRouting Tables:\n");

    for(i = 0; i < n; i++)
    {
        printf("\nNode %d\n", i);

        for(j = 0; j < n; j++)
        {
            printf("To Node %d -> Cost = %d\n", j, dist[i][j]);
        }
    }

    return 0;
}

/*
O/P:
Enter the number of nodes: 3
Enter the cost matrix:
0 1 5
1 0 2
5 2 0

Routing Tables:

Node 0
To Node 0 -> Cost = 0
To Node 1 -> Cost = 1
To Node 2 -> Cost = 3

Node 1
To Node 0 -> Cost = 1
To Node 1 -> Cost = 0
To Node 2 -> Cost = 2

Node 2
To Node 0 -> Cost = 3
To Node 1 -> Cost = 2
To Node 2 -> Cost = 0
*/