/*
Problem Statement
Find shortest distances from source vertex in a weighted graph with non-negative weights.

Input Format
n m
u v w
source

Output Format
Distances to all vertices.

Sample Input
5 6
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
1

Sample Output
0 2 3 9 6

Explanation
Shortest distances computed via priority queue.
*/

#include <stdio.h>

#define INF 9999999

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int adj[1000][1000];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            adj[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int src;
    scanf("%d", &src);

    int dist[1000];
    int visited[1000] = {0};

    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
    }
    
    dist[src] = 0;

    for (int count = 0; count < n; count++) {
        int min = INF, u = -1;
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }
        
        if (u == -1) break;
        
        visited[u] = 1;
        
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && adj[u][v] != INF && dist[u] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}