#include<iostream>
using namespace std;

int selectionSort(int arr[], int size, int k) {
    int i, j, min_index, swap = 0;
    for(int i=0; i<size-1; i++) {
        min_index = i;
        for(int j=i+1; j<size; j++) {
            if(arr[j]<arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
        swap++;
        if (swap == k) {
            return arr[k - 1];
        }
    }
}

int displayArr(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {9, 6, 5, 0, 8, 2, 7, 1, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted Array : ";displayArr(arr, size);
    int kthElement = selectionSort(arr, size, 3);
    cout<<"Sorted Array : ";displayArr(arr, size);
    cout<<"kth element in the array: "<<kthElement<<endl;

    return 0;
}