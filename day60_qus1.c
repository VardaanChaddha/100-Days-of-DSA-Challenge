/*
Problem Statement:
Check whether a given binary tree satisfies the Min-Heap property.

Input Format:
- First line contains integer N
- Second line contains level-order traversal

Output Format:
- Print YES if valid Min-Heap, otherwise NO

Example:
Input:
7
1 3 5 7 9 8 10

Output:
YES

Explanation:
Each parent node must be smaller than its children.
*/

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n == 0) {
        printf("YES\n");
        return 0;
    }

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int isValid = 1;
    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (2 * i + 1 < n && arr[2 * i + 1] < arr[i]) {
            isValid = 0;
            break;
        }
        if (2 * i + 2 < n && arr[2 * i + 2] < arr[i]) {
            isValid = 0;
            break;
        }
    }

    if (isValid) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}