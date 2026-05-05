/*
Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1

Explanation:
Preorder identifies root, inorder splits left and right subtrees.
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

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int preIndex = 0;

struct Node* buildTree(int in[], int pre[], int inSt, int inEnd) {
    if (inSt > inEnd) {
        return NULL;
    }

    struct Node* tNode = createNode(pre[preIndex++]);

    if (inSt == inEnd) {
        return tNode;
    }

    int inIndex = search(in, inSt, inEnd, tNode->data);

    tNode->left = buildTree(in, pre, inSt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

void postorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n == 0) return 0;

    int pre[1000];
    int in[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }

    preIndex = 0;
    struct Node* root = buildTree(in, pre, 0, n - 1);

    postorder(root);
    printf("\n");

    return 0;
}