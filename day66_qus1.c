/*
Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int dfsCheckCycleDirected(int u, struct Node* adj[], int visited[], int recStack[]) {
    visited[u] = 1;
    recStack[u] = 1;

    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->data;
        if (!visited[v]) {
            if (dfsCheckCycleDirected(v, adj, visited, recStack)) {
                return 1;
            }
        } else if (recStack[v]) {
            return 1; // Node is currently in the recursion stack
        }
        temp = temp->next;
    }
    
    recStack[u] = 0; // Remove from recursion stack before returning
    return 0;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[MAX] = {NULL};
    
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        // Directed graph, edge only from u to v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int visited[MAX] = {0};
    int recStack[MAX] = {0};
    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCheckCycleDirected(i, adj, visited, recStack)) {
                hasCycle = 1;
                break;
            }
        }
    }

    if (hasCycle) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}