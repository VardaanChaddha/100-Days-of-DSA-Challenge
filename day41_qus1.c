/*
Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }
    
    struct Node* temp = front;
    printf("%d\n", temp->data);
    front = front->next;
    
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    char op[20];
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &val);
            enqueue(val);
        } else if (strcmp(op, "dequeue") == 0) {
            dequeue();
        }
    }
    return 0;
}