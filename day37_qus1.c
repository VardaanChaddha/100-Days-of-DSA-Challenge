/*
Problem Statement:
Implement a Priority Queue using an array. An element with smaller value has higher priority.

Supported Operations:
- insert x
- delete
- peek

Input Format:
- First line contains integer N
- Next N lines contain operations

Output Format:
- Print the deleted or peeked element
- Print -1 if the queue is empty

Example:
Input:
5
insert 30
insert 10
insert 20
delete
peek

Output:
10
20
*/

#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    int n, val;
    char op[20];
    int pq[MAX];
    int size = 0;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            pq[size] = val;
            size++;
        } 
        else if (strcmp(op, "delete") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                int minIdx = 0;
                for (int j = 1; j < size; j++) {
                    if (pq[j] < pq[minIdx]) {
                        minIdx = j;
                    }
                }
                printf("%d\n", pq[minIdx]);
                
                for (int j = minIdx; j < size - 1; j++) {
                    pq[j] = pq[j + 1];
                }
                size--;
            }
        } 
        else if (strcmp(op, "peek") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                int minIdx = 0;
                for (int j = 1; j < size; j++) {
                    if (pq[j] < pq[minIdx]) {
                        minIdx = j;
                    }
                }
                printf("%d\n", pq[minIdx]);
            }
        }
    }

    return 0;
}