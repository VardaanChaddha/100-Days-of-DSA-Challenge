/*
Problem Statement
Using BFS or DFS, check if the entire graph is connected.

Input Format
n m
edges

Output Format
CONNECTED
NOT CONNECTED

Sample Input
4 2
1 2
3 4

Sample Output
NOT CONNECTED
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
    
    if (components == 1) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }
    
    return 0;
}