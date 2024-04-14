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

int main() {
    int arr[] = {39, 42, 95, 11, 15, 21, 30, 33};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Pivot : "<<pivotFind(arr, size);
    
    return 0;
}
