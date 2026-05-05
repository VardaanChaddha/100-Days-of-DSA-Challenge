/*
Problem: Count number of inversions using modified merge sort.
Inversion if i < j and a[i] > a[j].
*/

#include <stdio.h>

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid;
    int k = left;
    long long invCount = 0;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount = invCount + (mid - i);
        }
    }
    
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }
    
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long mid, invCount = 0;
    if (right > left) {
        mid = (right + left) / 2;
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid + 1, right);
    }
    return invCount;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[100000];
    int temp[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long ans = mergeSortAndCount(arr, temp, 0, n - 1);
    printf("%lld\n", ans);
    
    return 0;
}