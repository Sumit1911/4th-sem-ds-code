#include<iostream>
using namespace std;

int pivotFind(int arr[], int size) {
    int s=0, e=size-1, mid;
    mid = s + (e-s)/2;

    while (s<e) {
        if(arr[mid]>arr[0]) {
            s = mid+1;
        } else {
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(int arr[], int s, int e, int key) {
    int start = s, end = e;
    int mid;

    while (start<=end) {
        mid = start + (end-start)/2;
        if(arr[mid] == key) {
            return mid;
        } 
        //right wala part
        if(key>arr[mid]) {
            start = mid+1;
        } else { //left wala part
            end = mid-1;
        }
    }
    return -1;
}

int findPosition(int arr[], int size, int key) {
    int pivot = pivotFind(arr, size);
    if(key >= arr[pivot] && key <= arr[size-1]) {
        //binarySearch on 2nd line
        return binarySearch(arr, pivot, size-1, key);
    } else {
        //binarySearch on 1st line
        return binarySearch(arr, 0, pivot-1, key);
    }
}

int main() {
    int arr[] = {39, 42, 95, 11, 15, 21, 30, 33};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"key found at index : "<<findPosition(arr, size, 39);
    
    return 0;
}
