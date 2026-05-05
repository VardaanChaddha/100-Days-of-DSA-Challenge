/*
Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).
*/

#include <stdio.h>
#include <stdlib.h>

struct Element {
    int val;
    int index;
};

void merge(struct Element arr[], struct Element temp[], int left, int mid, int right, int ans[]) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i].val <= arr[j].val) {
            ans[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        ans[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(struct Element arr[], struct Element temp[], int left, int right, int ans[]) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, temp, left, mid, ans);
        mergeSort(arr, temp, mid + 1, right, ans);
        merge(arr, temp, left, mid, right, ans);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Element* arr = (struct Element*)malloc(n * sizeof(struct Element));
    struct Element* temp = (struct Element*)malloc(n * sizeof(struct Element));
    int* ans = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].index = i;
    }

    mergeSort(arr, temp, 0, n - 1, ans);

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    free(arr);
    free(temp);
    free(ans);

    return 0;
}