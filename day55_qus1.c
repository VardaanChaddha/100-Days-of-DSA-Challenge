/*
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print right view nodes

Example:
Input:
7
1 2 3 4 5 -1 6

Output:
1 3 6

Explanation:
At each level, the rightmost node is visible from the right view.
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

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n == 0) return 0;

    int arr[1000];
    for (int j = 0; j < n; j++) {
        scanf("%d", &arr[j]);
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

    struct Node* travQueue[1000];
    int tFront = 0, tRear = 0;
    travQueue[tRear++] = root;

    while (tFront < tRear) {
        int levelSize = tRear - tFront;
        
        for (int k = 0; k < levelSize; k++) {
            struct Node* curr = travQueue[tFront++];
            
            if (k == levelSize - 1) {
                printf("%d ", curr->data);
            }
            
            if (curr->left != NULL) {
                travQueue[tRear++] = curr->left;
            }
            if (curr->right != NULL) {
                travQueue[tRear++] = curr->right;
            }
        }
    }
    printf("\n");

    return 0;
}