#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partitionFirstPivot(int arr[], int s, int e) {
    int pivot = arr[s];
    int count = 0;
    for(int i = s + 1; i <= e; i++) {
        if(arr[i] < pivot) { // Count elements less than pivot
            count++;
        }
    }
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]); // Move pivot to correct position

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void QuickSortFirstPivot(int arr[], int s, int e) {
    if(s >= e) {
        return;
    }

    int p = partitionFirstPivot(arr, s, e);

    QuickSortFirstPivot(arr, s, p - 1);
    QuickSortFirstPivot(arr, p + 1, e);
}

int partitionLastPivot(int arr[], int s, int e) {
    int pivot = arr[e];
    int pivotIndex = s;

    for(int i = s; i < e; i++) {
        if(arr[i] <= pivot) {
            swap(arr[i], arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(arr[pivotIndex], arr[e]);
    return pivotIndex;
}

void QuickSortLastPivot(int arr[], int s, int e) {
    if(s >= e) {
        return;
    }

    int p = partitionLastPivot(arr, s, e);

    QuickSortLastPivot(arr, s, p - 1);
    QuickSortLastPivot(arr, p + 1, e);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//generating random nos.
int* randomArray(int n, int upperBound) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % upperBound;
    }
    return arr;
}

int main() {
    int numValues = 1000;
    int upperBound = 25;
    int* values = randomArray(numValues, upperBound);

    //time for choosing first element as pivot
    auto QuickSortFirstPivotStart = high_resolution_clock::now();
    QuickSortFirstPivot(values, 0, numValues - 1); 
    auto QuickSortFirstPivotStop = high_resolution_clock::now();
    auto QuickSortFirstPivotDuration = duration_cast<microseconds>(QuickSortFirstPivotStop - QuickSortFirstPivotStart);
    cout << "Time for choosing first element as pivot: " << QuickSortFirstPivotDuration.count() << " microseconds" << endl;

    // Reset array
    delete[] values;
    values = randomArray(numValues, upperBound);

    //time for choosing last element as pivot
    auto QuickSortLastPivotStart = high_resolution_clock::now();
    QuickSortLastPivot(values, 0, numValues - 1); 
    auto QuickSortLastPivotStop = high_resolution_clock::now();
    auto QuickSortLastPivotDuration = duration_cast<microseconds>(QuickSortLastPivotStop - QuickSortLastPivotStart);
    cout << "Time for choosing last element as pivot: " << QuickSortLastPivotDuration.count() << " microseconds" << endl;

    // Free allocated memory
    delete[] values;

    return 0;
}
