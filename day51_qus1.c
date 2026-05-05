/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
6 2 8 0 4 7 9
2 8

Output:
6
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

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* lcaBST(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data > n1 && root->data > n2) {
        return lcaBST(root->left, n1, n2);
    }
    if (root->data < n1 && root->data < n2) {
        return lcaBST(root->right, n1, n2);
    }
    return root;
}

int main() {
    int n, val, n1, n2;
    if (scanf("%d", &n) != 1) return 0;
    
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    scanf("%d %d", &n1, &n2);
    
    struct Node* ans = lcaBST(root, n1, n2);
    if (ans != NULL) {
        printf("%d\n", ans->data);
    }
    
    return 0;
}