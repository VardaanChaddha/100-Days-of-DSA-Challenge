/*
Problem: Given a target distance and cars' positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.
*/

#include <stdio.h>
#include <stdlib.h>

struct Car {
    int pos;
    int speed;
    double time;
};

int compareCars(const void* a, const void* b) {
    struct Car* carA = (struct Car*)a;
    struct Car* carB = (struct Car*)b;
    return carB->pos - carA->pos;
}

int main() {
    int target, n;
    if (scanf("%d %d", &target, &n) != 2) return 0;

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    struct Car cars[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].pos);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
        cars[i].time = (double)(target - cars[i].pos) / cars[i].speed;
    }

    qsort(cars, n, sizeof(struct Car), compareCars);

    int fleets = 0;
    double maxTime = 0.0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}