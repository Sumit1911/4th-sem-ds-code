#include<iostream>
using namespace std;
#include <chrono>
using namespace std;
using namespace std::chrono;

int partitionFirstPivot(int arr[], int s, int e) {
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++) { //for counting less no.
        if(arr[i] <= pivot) {
            count++;
        }
    }
    int pivotIndex = s + count; //pivot index
    swap(arr[pivotIndex], arr[s]); //swap the pivot to actual pos.

    int i=s, j=e;
    while (i<pivotIndex && j>pivotIndex) {
        while (arr[i]<pivot) {
            i++;
        }
        while (arr[j]>pivot) {
            j--;
        }
        if(i<pivotIndex && j>pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void QuickSortFirstPivot(int arr[], int s, int e) {
    if(s>=e) {
        return;
    }

    int p = partitionFirstPivot(arr, s, e); //finding pivot point

    QuickSortFirstPivot(arr, s, p-1);
    QuickSortFirstPivot(arr, p+1, e);
}

/**partitioning by choosing last element as pivot */
int partitionLastPivot(int arr[], int s, int e) {
    int pivot = arr[e];
    int pivotIndex = s; // Initialize pivot index to start

    for(int i = s; i < e; i++) {
        if(arr[i] <= pivot) {
            swap(arr[i], arr[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(arr[pivotIndex], arr[e]); // Place pivot in correct position
    return pivotIndex;
}
void QuickSortLastPivot(int arr[], int s, int e) {
    if(s>=e) {
        return;
    }

    int p = partitionLastPivot(arr, s, e); //finding pivot point

    QuickSortLastPivot(arr, s, p-1);
    QuickSortLastPivot(arr, p+1, e);
}

void printArray(int arr[], int size) {
    for (int i = 0; i <size; i++) {
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
    QuickSortFirstPivot(values, 0, numValues); 
    auto QuickSortFirstPivotStop = high_resolution_clock::now();
    auto QuickSortFirstPivotDuration = duration_cast<microseconds>(QuickSortFirstPivotStop - QuickSortFirstPivotStart);
    cout << "Time for choosing first element as pivot: " << QuickSortFirstPivotDuration.count() << " microseconds" << endl;

    //time for choosing last element as pivot
    auto QuickSortLastPivotStart = high_resolution_clock::now();
    QuickSortLastPivot(values, 0, numValues); 
    auto QuickSortLastPivotStop = high_resolution_clock::now();
    auto QuickSortLastPivotDuration = duration_cast<microseconds>(QuickSortLastPivotStop - QuickSortLastPivotStart);
    cout << "Time for choosing last element as pivot: " << QuickSortLastPivotDuration.count() << " microseconds" << endl;

    //time for choosing random element as pivot
    // auto QuickSortStart = high_resolution_clock::now();
    // QuickSort(values, 0, numValues); 
    // auto QuickSortStop = high_resolution_clock::now();
    // auto QuickSortDuration = duration_cast<microseconds>(QuickSortStop - QuickSortStart);
    // cout << "Time for choosing random element as pivot: " << QuickSortDuration.count() << " microseconds" << endl;

    // //time for choosing median element as pivot
    // auto QuickSortStart = high_resolution_clock::now();
    // QuickSort(values, 0, numValues); 
    // auto QuickSortStop = high_resolution_clock::now();
    // auto QuickSortDuration = duration_cast<microseconds>(QuickSortStop - QuickSortStart);
    // cout << "Time for median element as pivot: " << QuickSortDuration.count() << " microseconds" << endl;
    delete[] values;

    return 0;
}