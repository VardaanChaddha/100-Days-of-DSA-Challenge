/*
Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order
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

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node* adj[MAX] = {NULL};
    struct Node* tails[MAX] = {NULL};

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Undirected graph insertion
        struct Node* newNodeU = createNode(v);
        if (adj[u] == NULL) { adj[u] = tails[u] = newNodeU; } 
        else { tails[u]->next = newNodeU; tails[u] = newNodeU; }

        struct Node* newNodeV = createNode(u);
        if (adj[v] == NULL) { adj[v] = tails[v] = newNodeV; } 
        else { tails[v]->next = newNodeV; tails[v] = newNodeV; }
    }

    int s;
    if (scanf("%d", &s) != 1) return 0;

    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;

    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);

        struct Node* temp = adj[curr];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    return 0;
}