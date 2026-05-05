/*
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/

#include <stdio.h>

#define MAX 1000

int queue[MAX];
int front = 0;
int rear = 0;

int stack[MAX];
int top = -1;

void enqueue(int val) {
    queue[rear++] = val;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front == rear;
}

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int isStackEmpty() {
    return top == -1;
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    while (!isQueueEmpty()) {
        push(dequeue());
    }

    while (!isStackEmpty()) {
        enqueue(pop());
    }

    while (!isQueueEmpty()) {
        printf("%d ", dequeue());
    }
    printf("\n");

    return 0;
}