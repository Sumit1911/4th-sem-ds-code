#include <algorithm>
#include <iostream>
#include <cstdlib>  
#include <chrono>
using namespace std;
using namespace std::chrono;

int partition(int arr[], int s, int e) {
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
    cout << "Pivot element: " << pivot << endl;
    // cout << "Partitioned array: ";
    // for (int k = s; k <= e; k++) {
    //     cout << arr[k] << " ";
    // }
    // cout << endl;
    return pivotIndex;
}
int RandomizedQSpartition(int arr[], int s, int e) {
    int pivot = s + rand() % (e - s + 1);;
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
    // cout << "Pivot element: " << pivot << endl;
    return pivotIndex;
}

void QuickSort(int arr[], int s, int e) {
    if(s>=e) {
        return;
    }

    int p = partition(arr, s, e); //finding pivot point

    QuickSort(arr, s, p-1);
    QuickSort(arr, p+1, e);
}
void RandomizedQuickSort(int arr[], int s, int e) {
    if(s>=e) {
        return;
    }

    int randomIndex = s + rand() % (e - s + 1);
    swap(arr[randomIndex], arr[s]);
 
    int p = RandomizedQSpartition(arr, s, e); //finding pivot point

    QuickSort(arr, s, p-1);
    QuickSort(arr, p+1, e);
}

// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; ++i) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

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
    
    auto QuickSortStart = high_resolution_clock::now();
    QuickSort(values, 0, numValues); 
    // cout<<"Standard Quick Sort : ";
    // printArray(values, numValues);  
    auto QuickSortStop = high_resolution_clock::now();
    auto QuickSortDuration = duration_cast<microseconds>(QuickSortStop - QuickSortStart);
    cout << "Time taken by QuickSort: " << QuickSortDuration.count() << " microseconds" << endl;
   
//    delete[] values;
   
    auto RandomizedQuickSortStart = high_resolution_clock::now();
    RandomizedQuickSort(values, 0, numValues); 
    // cout<<"Randomized Quick Sort : ";
    // printArray(values, numValues);  
    auto RandomizedQuickSortStop = high_resolution_clock::now();
    auto RandomizedQuickSortDuration = duration_cast<microseconds>(RandomizedQuickSortStop - RandomizedQuickSortStart);
    cout << "Time taken by RandomizedQuickSort: " << RandomizedQuickSortDuration.count() << " microseconds" << endl;

    delete[] values;
    
    return 0;
}
