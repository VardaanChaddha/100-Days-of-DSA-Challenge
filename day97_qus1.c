/*
Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.
*/

#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compare(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

int heap[100000];
int size = 0;

void swap(int* a, int* b) {
    int temp = *a; 
    *a = *b; 
    *b = temp;
}

void insert(int val) {
    heap[size] = val;
    int i = size;
    size++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin() {
    if (size <= 0) return -1;
    if (size == 1) { 
        size--; 
        return heap[0]; 
    }
    
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    
    int i = 0;
    while (1) {
        int smallest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        
        if (l < size && heap[l] < heap[smallest]) smallest = l;
        if (r < size && heap[r] < heap[smallest]) smallest = r;
        
        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
    return root;
}

int getMin() {
    return size > 0 ? heap[0] : -1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Interval arr[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(struct Interval), compare);

    insert(arr[0].end);

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= getMin()) {
            extractMin();
        }
        insert(arr[i].end);
    }

    printf("%d\n", size);
    
    return 0;
}