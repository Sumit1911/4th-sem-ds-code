#include<iostream>
using namespace std;

// Function to find median of three elements
int medianOfThree(int arr[], int s, int e) {
    int mid = s + (e - s) / 2;
    if (arr[s] > arr[mid])
        swap(arr[s], arr[mid]);
    if (arr[s] > arr[e])
        swap(arr[s], arr[e]);
    if (arr[mid] > arr[e])
        swap(arr[mid], arr[e]);
    return mid;
}

int partition(int arr[], int s, int e) {
    int pivotIndex = medianOfThree(arr, s, e);
    int pivot = arr[pivotIndex];
    swap(arr[pivotIndex], arr[e]); // Move pivot to end

    int i = s - 1; // Index of smaller element
    for (int j = s; j < e; j++) {
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]); // Move pivot to its correct position
    return i + 1;
}

void QuickSort(int arr[], int s, int e) {
    if (s >= e) {
        return;
    }
    int p = partition(arr, s, e);

    QuickSort(arr, s, p - 1);
    QuickSort(arr, p + 1, e);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array : ";
    printArray(arr, size);

    QuickSort(arr, 0, size - 1);

    cout << "Sorted Array : ";
    printArray(arr, size);

    return 0;
}
