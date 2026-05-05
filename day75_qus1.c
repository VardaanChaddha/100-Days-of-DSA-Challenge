/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5

Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/

#include <stdio.h>

int main() {
    int arr[10000];
    int n = 0;
    
    while (scanf("%d", &arr[n]) == 1) {
        n++;
    }
    
    int maxLen = 0;
    
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = i; j < n; j++) {
            currentSum += arr[j];
            if (currentSum == 0) {
                if (j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                }
            }
        }
    }
    
    printf("%d\n", maxLen);
    
    return 0;
}