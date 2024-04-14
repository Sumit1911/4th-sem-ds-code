#include<iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int key, int &comparision) {
    if(l>r) {
        comparision++;
        return l;
    }
    int mid = (l+r)/2;
    if(key == arr[mid]) {
        return mid;
    } else if(key < arr[mid]) {
        binarySearch(arr, l, mid-1, key, comparision);
    } else {
        binarySearch(arr, mid+1, r, key, comparision);
    }
}

int insertionSort(int arr[], int size, int &comparision) {
    for(int j=1; j<size; j++) {
        int key = arr[j];
        int i = j-1;
        int insertPos = binarySearch(arr, 0, i, key, comparision);
        while(i>=insertPos) {
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
    int comparision = 0;
    cout<<"Original Array : "; displayArray(arr, size);
    insertionSort(arr, size, comparision);
    cout<<"Comparision : "<<comparision<<endl;
    cout<<"Sorted Array : "; displayArray(arr, size);

    return 0;
}