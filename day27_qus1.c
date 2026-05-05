/*
Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head1 == NULL) { head1 = newNode; tail1 = newNode; } 
        else { tail1->next = newNode; tail1 = newNode; }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head2 == NULL) { head2 = newNode; tail2 = newNode; } 
        else { tail2->next = newNode; tail2 = newNode; }
    }

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;
    int diff;

    if (n > m) {
        diff = n - m;
        for (int i = 0; i < diff; i++) ptr1 = ptr1->next;
    } else {
        diff = m - n;
        for (int i = 0; i < diff; i++) ptr2 = ptr2->next;
    }

    int found = 0;
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            found = 1;
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (!found) {
        printf("No Intersection\n");
    }

    return 0;
}