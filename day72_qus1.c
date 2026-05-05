/*
Problem Statement
Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

Input Format
A single string s.

Output Format
Print the first repeated character. If no character is repeated, print -1.

Sample Input
geeksforgeeks

Sample Output
e
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[10000];
    if (scanf("%s", s) != 1) return 0;

    int first_seen[256];
    int second_seen[256];
    for (int i = 0; i < 256; i++) {
        first_seen[i] = -1;
        second_seen[i] = -1;
    }

    int min_second_index = 9999999;
    char ans = '-';

    for (int i = 0; s[i] != '\0'; i++) {
        int c = s[i];
        if (first_seen[c] == -1) {
            first_seen[c] = i;
        } else if (second_seen[c] == -1) {
            second_seen[c] = i;
            if (i < min_second_index) {
                min_second_index = i;
                ans = c;
            }
        }
    }

    if (ans != '-') {
        printf("%c\n", ans);
    } else {
        printf("-1\n");
    }

    return 0;
}