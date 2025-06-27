#include <stdio.h>
#include <stdlib.h>

// Function to calculate mean
double calculate_mean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

// Function to calculate median
double calculate_median(int arr[], int size) {
    // Sort the array
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Calculate median
    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        return arr[size / 2];
    }
}

// Function to calculate mode
int calculate_mode(int arr[], int size) {
    int max_count = 0;
    int mode = arr[0];

    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            mode = arr[i];
        }
    }

    return mode;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    double mean = calculate_mean(arr, size);
    double median = calculate_median(arr, size);
    int mode = calculate_mode(arr, size);

    printf("Mean: %.2f\n", mean);
    printf("Median: %.2f\n", median);
    printf("Mode: %d\n", mode);

    return 0;
}