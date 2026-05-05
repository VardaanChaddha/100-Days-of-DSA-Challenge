/*
Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (vertices)
- m (edges)
- m pairs (u, v)

Output:
- n x n adjacency matrix
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    if (scanf("%d", &n) != 1) return 0;
    if (scanf("%d", &m) != 1) return 0;

    int matrix[1000][1000] = {0};

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        if (u >= 0 && u < n && v >= 0 && v < n) {
            matrix[u][v] = 1;
            matrix[v][u] = 1; 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}