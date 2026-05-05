/*
Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
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

void dfsTopoSort(int u, struct Node* adj[], int visited[], int stack[], int* top) {
    visited[u] = 1;

    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->data;
        if (!visited[v]) {
            dfsTopoSort(v, adj, visited, stack, top);
        }
        temp = temp->next;
    }
    
    stack[++(*top)] = u; // Push to stack after visiting all descendants
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[MAX] = {NULL};
    
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfsTopoSort(i, adj, visited, stack, &top);
        }
    }

    // Print elements in reversed finishing time order
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");

    return 0;
}