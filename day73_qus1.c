/*
Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

Input Format
A single string s.

Output Format
Print the first non-repeating character or '$' if none exists.

Sample Input
geeksforgeeks

Sample Output
f

Explanation
The character 'f' occurs only once in the string and appears before any other non-repeating character.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[10000];
    if (scanf("%s", s) != 1) return 0;

    int freq[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        freq[(int)s[i]]++;
    }

    char ans = '$';
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[(int)s[i]] == 1) {
            ans = s[i];
            break;
        }
    }

    printf("%c\n", ans);

    return 0;
}