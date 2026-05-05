/*
Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printLevelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* curr = queue[front++];
        printf("%d ", curr->data);

        if (curr->left != NULL) {
            queue[rear++] = curr->left;
        }
        if (curr->right != NULL) {
            queue[rear++] = curr->right;
        }
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n == 0) return 0;

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (arr[0] == -1) return 0;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (front < rear && i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    printLevelOrder(root);

    return 0;
}