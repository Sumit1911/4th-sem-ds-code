#include<iostream>
using namespace std;

int insertionSort(int arr[], int size) {
    for(int j=1; j<size; j++) {
        int key = arr[j];
        int i = j-1;
        while(i>=0 && arr[i]>key) {
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}

void displayArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {10, 7, 5, 0, 8, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original Array : "; displayArray(arr, size);
    insertionSort(arr, size);
    cout<<"Sorted Array : "; displayArray(arr, size);

    return 0;
}