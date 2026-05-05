/*
Problem Statement
Implement a hash table using quadratic probing with formula:

h(k, i) = (h(k) + i*i) % m

Input Format
Same as previous.

Output Format
Result of SEARCH operations.

Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15

Sample Output
FOUND
NOT FOUND

Explanation
Collisions resolved using i^2 jumps.
*/

#include <stdio.h>
#include <string.h>

int main() {
    int m, n;
    if (scanf("%d", &m) != 1) return 0;
    if (scanf("%d", &n) != 1) return 0;

    int table[1000];
    for (int i = 0; i < m; i++) table[i] = -1;

    char op[10];
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &val);
        if (strcmp(op, "INSERT") == 0) {
            int j = 0;
            while (j < m) {
                int idx = ((val % m) + j * j) % m;
                if (table[idx] == -1 || table[idx] == val) {
                    table[idx] = val;
                    break;
                }
                j++;
            }
        } else if (strcmp(op, "SEARCH") == 0) {
            int j = 0;
            int found = 0;
            while (j < m) {
                int idx = ((val % m) + j * j) % m;
                if (table[idx] == val) {
                    found = 1;
                    break;
                }
                if (table[idx] == -1) {
                    break;
                }
                j++;
            }
            if (found) printf("FOUND\n");
            else printf("NOT FOUND\n");
        }
    }
    return 0;
}