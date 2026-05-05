/*
Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)

Output:
- Print queue elements from front to rear after operations, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
30 40 50 10 20

Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.
*/

#include <stdio.h>

#define MAX 1000

int main() {
    int n, m, val;
    int queue[MAX];
    int front = 0, rear = 0, size = 0;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        queue[rear] = val;
        rear = (rear + 1) % MAX;
        size++;
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        if (size > 0) {
            val = queue[front];
            front = (front + 1) % MAX;
            
            queue[rear] = val;
            rear = (rear + 1) % MAX;
        }
    }

    int curr = front;
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[curr]);
        curr = (curr + 1) % MAX;
    }
    printf("\n");

    return 0;
}