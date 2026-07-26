//Q5:Take an example subnet of hosts and obtain a broadcast tree for the subnet. 

#include <stdio.h>

int graph[10][10], visited[10], n;

void BFS(int start)
{
    int queue[10], front = 0, rear = 0;
    int i, current;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBroadcast Tree:\n");

    while(front < rear)
    {
        current = queue[front++];

        for(i = 0; i < n; i++)
        {
            if(graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
                printf("%d --> %d\n", current, i);
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of hosts: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source host: ");
    scanf("%d", &start);

    BFS(start);

    return 0;
}

/*O/P:
Enter number of hosts: 5
Enter adjacency matrix:
1 0 0 1 1
0 0 0 0 1
1 1 0 1 0
0 1 0 1 1
0 1 0 1 0
Enter source host: 0

Broadcast Tree:
0 --> 3
0 --> 4
3 --> 1
*/