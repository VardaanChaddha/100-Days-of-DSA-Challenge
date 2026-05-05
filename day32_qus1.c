/*
Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10
*/

#include <stdio.h>

#define MAX 1000

int main() {
    int n, m, val;
    int stack[MAX];
    int top = -1;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (top < MAX - 1) {
            top++;
            stack[top] = val;
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        if (top >= 0) {
            top--;
        }
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}