/*
Problem: Implement topological sorting using in-degree array and queue (Kahn's Algorithm).
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
    int inDegree[MAX] = {0};
    
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
        
        inDegree[v]++; // Increment in-degree for the destination node
    }

    int queue[MAX];
    int front = 0, rear = 0;

    // Enqueue all vertices with 0 in-degree
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        struct Node* temp = adj[curr];
        while (temp != NULL) {
            int neighbor = temp->data;
            inDegree[neighbor]--;
            
            if (inDegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    return 0;
}