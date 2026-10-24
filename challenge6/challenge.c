#include <stdio.h>

int main() {
    int a[12], n, i, j, k, t;
    int sum = 0, min, max, second = -1;
    int peak = 0, count = 1, longest = 1;
    int r, d, division = 0;
    float avg;

    printf("enter the number of readings: ");
    scanf("%d", &n);

    while (n < 5 || n > 12) {
        printf("enter n between 5 and 12: ");
        scanf("%d", &n);
    }

    for (i = 0; i < n; i++) {
        printf("enter the number: ");
        scanf("%d", &a[i]);

        while (a[i] < 0 || a[i] > 1000) {
            printf("enter a valid number: ");
            scanf("%d", &a[i]);
        }
    }

    printf("original array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    min = a[0];
    max = a[0];

    for (i = 0; i < n; i++) {
 sum = sum + a[i];

        if (a[i] < min)
            min = a[i];

        if (a[i] > max)
            max = a[i];
    }

    avg = sum / (float)n;

    printf("\nsum = %d\n", sum);
    printf("average = %.2f\n", avg);
    printf("minimum = %d\n", min);
    printf("maximum = %d\n", max);

    for (i = 0; i < n; i++) {
        if (a[i] < max && a[i] > second)
            second = a[i];
    }

    if (second == -1)
        printf("no second largest value\n");
    else
        printf("second largest = %d\n", second);

    for (i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
            peak++;
    }

    printf("number of peaks = %d\n", peak);

    for (i = 1; i < n; i++) {
        if (a[i] > a[i - 1])
            count++;
        else
           count = 1;

        if (count > longest)
            longest = count;
    }

    printf("longest increasing run = %d\n", longest);

    printf("enter k: ");
    scanf("%d", &k);

    k = k % n;

    if (k < 0)
        k = k + n;

    for (j = 0; j < k; j++) {
        t = a[n - 1];

        for (i = n - 1; i > 0; i--) {
            a[i] = a[i - 1];
        }

        a[0] = t;
    }

    printf("rotated array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("rotated array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\nenter last two digits of registration number: ");
    scanf("%d", &r);

    while (r < 0 || r > 99) {
        printf("enter a number between 0 and 99: ");
        scanf("%d", &r);
    }

    d = (r % 9) + 1;

    for (i = 0; i < n; i++) {
        if (a[i] % d == 0)
            division++;
    }

    printf("D = %d\n", d);
    printf("divisible count = %d\n", division);

    return 0;
}
