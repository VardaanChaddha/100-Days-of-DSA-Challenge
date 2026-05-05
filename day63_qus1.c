/*
Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order
*/

#include <stdio.h>
#include <stdlib.h>

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

void dfs(int u, struct Node* adj[], int visited[]) {
    visited[u] = 1;
    printf("%d ", u);

    struct Node* temp = adj[u];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(temp->data, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[1000] = {NULL};
    struct Node* tails[1000] = {NULL};

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        struct Node* newNodeU = createNode(v);
        if (adj[u] == NULL) {
            adj[u] = newNodeU;
            tails[u] = newNodeU;
        } else {
            tails[u]->next = newNodeU;
            tails[u] = newNodeU;
        }

        struct Node* newNodeV = createNode(u);
        if (adj[v] == NULL) {
            adj[v] = newNodeV;
            tails[v] = newNodeV;
        } else {
            tails[v]->next = newNodeV;
            tails[v] = newNodeV;
        }
    }

    int s;
    if (scanf("%d", &s) != 1) return 0;

    int visited[1000] = {0};
    dfs(s, adj, visited);
    printf("\n");

    return 0;
}