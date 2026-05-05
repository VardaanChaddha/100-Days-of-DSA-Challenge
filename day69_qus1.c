/*
Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

Input:
- n vertices
- m edges (u, v, w)
- source s

Output:
- Space-separated shortest distances from source
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define INF 9999999

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int adj[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = INF;
        }
    }

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int s;
    if (scanf("%d", &s) != 1) s = 0;

    int dist[MAX];
    int inPQ[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        inPQ[i] = 1;
    }
    dist[s] = 0;

    for (int count = 0; count < n; count++) {
        int min = INF, u = -1;
        for (int i = 0; i < n; i++) {
            if (inPQ[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        inPQ[u] = 0;

        for (int v = 0; v < n; v++) {
            if (inPQ[v] && adj[u][v] != INF && dist[u] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    return 0;
}