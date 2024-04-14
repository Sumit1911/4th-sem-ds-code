#include<iostream>
using namespace std;

int BinarySearch(int arr[], int key, int size) {
    int start = 0, end = size-1, mid; 
    while (start<end) {
        mid = (start+end)/2;
        if(key == arr[mid]) {
            return 1;
        } else if(key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int key = 3;
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = BinarySearch(arr, key, size);
    if(result == 1) {
        cout<<"Key Found!";
    } else {
        cout<<"Key not Found!";
    }
    return 0;
}