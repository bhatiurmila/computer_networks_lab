/*Q4: Implement Dijsktra’s algorithm to compute the shortest path through a network 
*/

#include <stdio.h>
#define MAX 100
#define INF 9999

int main(){
    int n, cost[MAX][MAX], dist[MAX], visited[MAX];
    int src, i, j, u, min;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (enter %d for no direct edge):\n", INF);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Cost[%d][%d]: ", i, j);
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter source node (0 to %d): ", n - 1);
    scanf("%d", &src);

    // Initialize distances and visited array
    for(i = 0; i < n; i++){
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for(i = 0; i < n - 1; i++){
        // Find the unvisited node with the smallest distance
        min = INF;
        u = -1;
        for(j = 0; j < n; j++){
            if(!visited[j] && dist[j] <= min){
                min = dist[j];
                u = j;
            }
        }

        if(u == -1)
            break; // Remaining nodes are unreachable

        visited[u] = 1;

        // Update distances of adjacent nodes
        for(j = 0; j < n; j++){
            if(!visited[j] && cost[u][j] != INF && 
                dist[u] + cost[u][j] < dist[j]){
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest distances from node %d:\n", src);
    for(i = 0; i < n; i++){
        if (dist[i] == INF)
            printf("Node %d: Unreachable\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }
    return 0;
}

/*
O/P:
Enter number of nodes: 4
Enter the adjacency matrix (enter 9999 for no direct edge):
Cost[0][0]: 2
Cost[0][1]: 3
Cost[0][2]: 1
Cost[0][3]: 0
Cost[1][0]: 1
Cost[1][1]: 2
Cost[1][2]: 3
Cost[1][3]: 4
Cost[2][0]: 0
Cost[2][1]: 9
Cost[2][2]: 8
Cost[2][3]: 3
Cost[3][0]: 5
Cost[3][1]: 6
Cost[3][2]: 7
Cost[3][3]: 8
Enter source node (0 to 3): 0

Shortest distances from node 0:
Node 0: 0
Node 1: 3
Node 2: 1
Node 3: 0
*/