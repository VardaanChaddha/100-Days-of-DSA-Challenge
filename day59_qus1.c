/*
Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal

Output Format:
- Print preorder traversal of constructed tree

Example:
Input:
5
4 2 5 1 3
4 5 2 3 1

Output:
1 2 4 5 3

Explanation:
Postorder gives root at end, inorder divides left and right subtrees.
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

struct Node* buildTree(int in[], int post[], int inSt, int inEnd, int* pIndex) {
    if (inSt > inEnd) {
        return NULL;
    }

    struct Node* node = createNode(post[*pIndex]);
    (*pIndex)--;

    if (inSt == inEnd) {
        return node;
    }

    int inIndex = search(in, inSt, inEnd, node->data);

    node->right = buildTree(in, post, inIndex + 1, inEnd, pIndex);
    node->left = buildTree(in, post, inSt, inIndex - 1, pIndex);

    return node;
}

void preorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n == 0) return 0;

    int in[1000];
    int post[1000];

    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }

    int pIndex = n - 1;
    struct Node* root = buildTree(in, post, 0, n - 1, &pIndex);

    preorder(root);
    printf("\n");

    return 0;
}