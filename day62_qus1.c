/*
Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (vertices)
- m (edges)
- edges (u, v)

Output:
- List of adjacency lists for each vertex
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

int main() {
    int n, m;
    if (scanf("%d", &n) != 1) return 0;
    if (scanf("%d", &m) != 1) return 0;

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

    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}