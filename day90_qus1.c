/*
Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.
*/

#include <stdio.h>

int isValid(int arr[], int n, int k, long long maxTime) {
    int painters = 1;
    long long currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime) {
            return 0;
        }
        
        if (currentTime + arr[i] > maxTime) {
            painters++;
            currentTime = arr[i];
            
            if (painters > k) {
                return 0;
            }
        } else {
            currentTime += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    
    int arr[100000];
    long long sum = 0;
    int max = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    long long low = max;
    long long high = sum;
    long long ans = -1;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        
        if (isValid(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}