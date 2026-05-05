/*
Problem Statement:
Check whether a given binary tree is symmetric around its center.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)

Output Format:
- Print YES if symmetric, otherwise NO

Example:
Input:
7
1 2 2 3 4 4 3

Output:
YES

Explanation:
Left subtree is a mirror image of the right subtree.
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

int isMirror(struct Node* node1, struct Node* node2) {
    if (node1 == NULL && node2 == NULL) {
        return 1;
    }
    if (node1 != NULL && node2 != NULL && node1->data == node2->data) {
        return isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left);
    }
    return 0;
}

int isSymmetric(struct Node* root) {
    if (root == NULL) {
        return 1;
    }
    return isMirror(root->left, root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n == 0) {
        printf("YES\n");
        return 0;
    }

    int arr[1000];
    for (int j = 0; j < n; j++) {
        scanf("%d", &arr[j]);
    }

    if (arr[0] == -1) {
        printf("YES\n");
        return 0;
    }

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

    if (isSymmetric(root)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}