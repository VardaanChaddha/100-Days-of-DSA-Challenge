/*
Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO
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

int dfsCheckCycle(int u, int parent, struct Node* adj[], int visited[]) {
    visited[u] = 1;

    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->data;
        if (!visited[v]) {
            if (dfsCheckCycle(v, u, adj, visited)) {
                return 1;
            }
        } else if (v != parent) {
            return 1; // Visited node that is not the parent means cycle exists
        }
        temp = temp->next;
    }
    return 0;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[MAX] = {NULL};
    
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNodeU = createNode(v);
        newNodeU->next = adj[u];
        adj[u] = newNodeU;

        struct Node* newNodeV = createNode(u);
        newNodeV->next = adj[v];
        adj[v] = newNodeV;
    }

    int visited[MAX] = {0};
    int hasCycle = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCheckCycle(i, -1, adj, visited)) {
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