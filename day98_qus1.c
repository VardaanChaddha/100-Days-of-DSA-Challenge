/*
Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.
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

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Interval arr[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(struct Interval), compare);

    int index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[index].end >= arr[i].start) {
            if (arr[i].end > arr[index].end) {
                arr[index].end = arr[i].end;
            }
        } else {
            index++;
            arr[index] = arr[i];
        }
    }

    for (int i = 0; i <= index; i++) {
        printf("%d %d\n", arr[i].start, arr[i].end);
    }

    return 0;
}