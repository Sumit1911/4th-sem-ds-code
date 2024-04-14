#include<iostream>
using namespace std;

int findPeakElement(int arr[], int size) {
    int s=0, e = size-1;
    int mid = s+(e-s)/2;

    while (s<e) {
        if(arr[mid]<arr[mid+1]) {
            s = mid+1;
        } else {
            e = mid;
        }
        mid = s+(e-s)/2;
    }
    return arr[s];
    
}

int main() {
    int arr[] = {100, 20, 15, -2, 23, 90, 67};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Peak Element : "<<findPeakElement(arr, size);
    return 0;
}
