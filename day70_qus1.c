/*
Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.

Input:
- n vertices
- m edges (u,v,w)

Output:
- Shortest distances OR NEGATIVE CYCLE
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 10000
#define INF 9999999

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Edge edges[MAX_EDGES];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    int dist[1000];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[0] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    int negative_cycle = 0;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            negative_cycle = 1;
            break;
        }
    }

    if (negative_cycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF) printf("INF ");
            else printf("%d ", dist[i]);
        }
        printf("\n");
    }

    return 0;
}