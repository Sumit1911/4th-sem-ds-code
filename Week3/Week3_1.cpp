#include<iostream>
using namespace std;

int bubbleSort(int arr[], int size) {
    int i, j, swapped, swap = 0;
    for(i=0; i<size; i++) {
        swapped = 0;
        for(j=0; j<size-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped++;
                swap++;
            }
        }
        if(swapped == 0) {
            break;
        }
    }
    return swap;
}
int displayArr(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {6, -1, 2, 0, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Unsorted Array : ";displayArr(arr, size);
    int noOfSwap = bubbleSort(arr, size);
    cout<<"Sorted Array : ";displayArr(arr, size);
    cout<<"Total No. Of Swap after Sorting : "<<noOfSwap;
    return 0;
}