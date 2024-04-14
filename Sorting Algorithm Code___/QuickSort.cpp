#include<iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[s];

    int count = 0;
    for(int i=s+1; i<=e; i++) {
        if(arr[i]<=pivot) {
            count++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    //left and right wala part sambhalte hai
    int i=s, j=e;

    while (i<pivotIndex && j>pivotIndex) {
        while(arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if(i<pivotIndex && j>pivotIndex) {
            swap(arr[i++], arr[j--]);
        }   
    }
    return pivotIndex;
}

void QuickSort(int arr[], int s, int e) {
    //base case
    if(s>=e) {
        return;
    }

    int p = partition(arr, s, e);  //finding pivot point

    //left part sort karna hai
    QuickSort(arr, s, p-1);

    //right part sort karna hai
    QuickSort(arr, p+1, e);

}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr)/sizeof(arr[0]);

    QuickSort(arr, 0, size-1);

    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}