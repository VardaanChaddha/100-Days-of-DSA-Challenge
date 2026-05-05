/*
Problem Statement
Using DFS or BFS, count number of connected components.

Input Format
n m
edges

Output Format
Number of connected components.

Sample Input
6 3
1 2
2 3
5 6

Sample Output
3

Explanation
Components: {1,2,3}, {4}, {5,6}
*/

#include <stdio.h>

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    int adj[1005][1005] = {0};
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    int visited[1005] = {0};
    int components = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            
            int queue[1005];
            int front = 0, rear = 0;
            
            queue[rear++] = i;
            visited[i] = 1;
            
            while (front < rear) {
                int curr = queue[front++];
                
                for (int v = 1; v <= n; v++) {
                    if (adj[curr][v] && !visited[v]) {
                        visited[v] = 1;
                        queue[rear++] = v;
                    }
                }
            }
        }
    }
    
    printf("%d\n", components);
    
    return 0;
}