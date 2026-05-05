/*
Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

Input Format
First line contains an integer n representing number of votes.
Second line contains n space-separated strings representing candidate names.

Output Format
Print the name of the winning candidate followed by the number of votes received.

Sample Input
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

Sample Output
john 4

Explanation
Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    char votes[1000][50];
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }
    
    qsort(votes, n, 50, compare);
    
    int maxCount = 0;
    char winner[50];
    int currentCount = 1;
    
    strcpy(winner, votes[0]);
    maxCount = 1;
    
    for (int i = 1; i < n; i++) {
        if (strcmp(votes[i], votes[i-1]) == 0) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                strcpy(winner, votes[i-1]);
            }
            currentCount = 1;
        }
    }
    
    if (currentCount > maxCount) {
        maxCount = currentCount;
        strcpy(winner, votes[n-1]);
    }
    
    printf("%s %d\n", winner, maxCount);
    
    return 0;
}