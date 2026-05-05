/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values

Output Format:
- Print the LCA value

Example:
Input:
7
1 2 3 4 5 6 7
4 5

Output:
2
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

struct Node* lcaBinaryTree(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    
    struct Node* left_lca = lcaBinaryTree(root->left, n1, n2);
    struct Node* right_lca = lcaBinaryTree(root->right, n1, n2);
    
    if (left_lca != NULL && right_lca != NULL) {
        return root;
    }
    
    if (left_lca != NULL) {
        return left_lca;
    } else {
        return right_lca;
    }
}

int main() {
    int n, n1, n2;
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
    
    scanf("%d %d", &n1, &n2);
    
    struct Node* ans = lcaBinaryTree(root, n1, n2);
    if (ans != NULL) {
        printf("%d\n", ans->data);
    }
    
    return 0;
}