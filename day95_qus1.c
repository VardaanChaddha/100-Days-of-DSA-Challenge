/*
Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

void insertSorted(struct Node** head, float val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    
    if (*head == NULL || (*head)->data >= val) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    float arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    struct Node** buckets = (struct Node**)calloc(n, sizeof(struct Node*));

    for (int i = 0; i < n; i++) {
        int bucketIdx = n * arr[i];
        insertSorted(&buckets[bucketIdx], arr[i]);
    }

    for (int i = 0; i < n; i++) {
        struct Node* curr = buckets[i];
        while (curr != NULL) {
            printf("%f ", curr->data);
            curr = curr->next;
        }
    }
    printf("\n");
    
    return 0;
}