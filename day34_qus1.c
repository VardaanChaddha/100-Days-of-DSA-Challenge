/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        return 0;
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int main() {
    char token[100];
    struct Node* stack = NULL;

    while (scanf("%s", token) == 1) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        } else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);

            switch (token[0]) {
                case '+':
                    push(&stack, val2 + val1);
                    break;
                case '-':
                    push(&stack, val2 - val1);
                    break;
                case '*':
                    push(&stack, val2 * val1);
                    break;
                case '/':
                    push(&stack, val2 / val1);
                    break;
            }
        }
    }

    printf("%d\n", pop(&stack));

    return 0;
}