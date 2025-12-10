#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

double mean(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

double median(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        return arr[n/2];
}

int* mode(int arr[], int n, int *modeCount) {
    qsort(arr, n, sizeof(int), compare);

    int maxFreq = 1, currentFreq = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1])
            currentFreq++;
        else
            currentFreq = 1;
        if (currentFreq > maxFreq)
            maxFreq = currentFreq;
    }

    int *modes = malloc(n * sizeof(int));
    int index = 0;
    currentFreq = 1;

    for (int i = 1; i <= n; i++) {
        if (i < n && arr[i] == arr[i-1])
            currentFreq++;
        else {
            if (currentFreq == maxFreq)
                modes[index++] = arr[i-1];
            currentFreq = 1;
        }
    }

    *modeCount = index;
    return modes;
}

int main() {
    int arr[] = {4, 1, 2, 2, 5, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mean: %.2f\n", mean(arr, n));
    printf("Median: %.2f\n", median(arr, n));

    int modeCount = 0;
    int *m = mode(arr, n, &modeCount);
    printf("Mode(s): ");
    for (int i = 0; i < modeCount; i++)
        printf("%d ", m[i]);
    printf("\n");

    free(m);
    return 0;
}
