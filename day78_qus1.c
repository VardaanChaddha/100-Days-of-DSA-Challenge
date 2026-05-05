/*
Problem Statement
Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim's algorithm.

Input Format
n m
u v w
...

Output Format
Total weight of MST.

Sample Input
4 5
1 2 3
1 3 5
2 3 1
2 4 4
3 4 2

Sample Output
6

Explanation
One possible MST edges: (2-3), (3-4), (1-2)
*/

#include <stdio.h>

#define INF 9999999

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    int adj[1005][1005];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = INF;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (w < adj[u][v]) {
            adj[u][v] = w;
            adj[v][u] = w;
        }
    }
    
    int inMST[1005] = {0};
    int key[1005];
    
    for (int i = 1; i <= n; i++) {
        key[i] = INF;
    }
    
    key[1] = 0;
    int totalWeight = 0;
    
    for (int count = 0; count < n; count++) {
        int min = INF;
        int u = -1;
        
        for (int i = 1; i <= n; i++) {
            if (!inMST[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }
        
        if (u == -1) break;
        
        inMST[u] = 1;
        totalWeight += key[u];
        
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != INF && !inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }
    
    printf("%d\n", totalWeight);
    
    return 0;
}