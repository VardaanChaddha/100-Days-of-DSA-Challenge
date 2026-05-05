/*
Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.

Sample Input
5 3
1 2 8 4 9

Sample Output
3

Explanation
Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.
*/

#include <stdio.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int stalls[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (stalls[j] > stalls[j + 1]) {
                int temp = stalls[j];
                stalls[j] = stalls[j + 1];
                stalls[j + 1] = temp;
            }
        }
    }

    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 1;
        int lastPos = stalls[0];

        for (int i = 1; i < n; i++) {
            if (stalls[i] - lastPos >= mid) {
                count++;
                lastPos = stalls[i];
            }
        }

        if (count >= k) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}