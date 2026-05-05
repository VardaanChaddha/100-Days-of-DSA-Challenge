/*
Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int main() {
    char infix[MAX];
    char stack[MAX];
    int top = -1;

    if (scanf("%s", infix) != 1) return 0;

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            printf("%c", ch);
        } 
        else if (ch == '(') {
            top++;
            stack[top] = ch;
        } 
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top]);
                top--;
            }
            if (top != -1) {
                top--;
            }
        } 
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                printf("%c", stack[top]);
                top--;
            }
            top++;
            stack[top] = ch;
        }
    }

    while (top != -1) {
        printf("%c", stack[top]);
        top--;
    }
    printf("\n");

    return 0;
}