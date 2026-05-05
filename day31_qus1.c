/*
Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10
*/

#include <stdio.h>

#define MAX 1000

int main() {
    int n, type, val;
    int stack[MAX];
    int top = -1;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &val);
            if (top < MAX - 1) {
                top++;
                stack[top] = val;
            }
        } else if (type == 2) {
            if (top == -1) {
                printf("Stack Underflow\n");
            } else {
                printf("%d\n", stack[top]);
                top--;
            }
        } else if (type == 3) {
            if (top == -1) {
                printf("\n");
            } else {
                for (int j = top; j >= 0; j--) {
                    printf("%d ", stack[j]);
                }
                printf("\n");
            }
        }
    }

    return 0;
}