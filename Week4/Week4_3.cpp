#include<iostream>
using namespace std;

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

void printArray(int arr[], int size) {
    for (int i = 0; i <size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Unsorted Array : ";
    printArray(arr, size);

    QuickSort(arr, 0, size-1);

    cout<<"Sorted Array : ";
    printArray(arr, size);

    return 0;
}