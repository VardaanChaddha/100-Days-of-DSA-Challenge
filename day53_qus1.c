/*
Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
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

struct QNode {
    struct Node* node;
    int hd;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n == 0) return 0;
    
    int arr[1000];
    for (int j = 0; j < n; j++) {
        scanf("%d", &arr[j]);
    }
    
    if (arr[0] == -1) return 0;
    
    struct Node* root = createNode(arr[0]);
    struct Node* nodeQueue[1000];
    int front = 0, rear = 0;
    
    nodeQueue[rear++] = root;
    int i = 1;
    
    while (front < rear && i < n) {
        struct Node* curr = nodeQueue[front++];
        
        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            nodeQueue[rear++] = curr->left;
        }
        i++;
        
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            nodeQueue[rear++] = curr->right;
        }
        i++;
    }
    
    struct QNode queue[1000];
    int qFront = 0, qRear = 0;
    
    queue[qRear].node = root;
    queue[qRear].hd = 0;
    qRear++;
    
    int cols[2000][1000];
    int counts[2000] = {0};
    int minHd = 0, maxHd = 0;
    
    while (qFront < qRear) {
        struct Node* curr = queue[qFront].node;
        int hd = queue[qFront].hd;
        qFront++;
        
        int index = hd + 1000;
        cols[index][counts[index]++] = curr->data;
        
        if (hd < minHd) minHd = hd;
        if (hd > maxHd) maxHd = hd;
        
        if (curr->left != NULL) {
            queue[qRear].node = curr->left;
            queue[qRear].hd = hd - 1;
            qRear++;
        }
        if (curr->right != NULL) {
            queue[qRear].node = curr->right;
            queue[qRear].hd = hd + 1;
            qRear++;
        }
    }
    
    for (int k = minHd; k <= maxHd; k++) {
        int index = k + 1000;
        for (int m = 0; m < counts[index]; m++) {
            printf("%d ", cols[index][m]);
        }
        printf("\n");
    }
    
    return 0;
}