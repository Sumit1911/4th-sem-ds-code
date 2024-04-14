#include <iostream>

using namespace std;

// Function to find the maximum element in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// Function to perform counting sort based on the digit represented by exp
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    // Count the occurrences of each digit in arr
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Cumulative sum of count to determine the position of each element in output
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

// Function to print the elements of the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    radixSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
