#include<iostream>
using namespace std;

int cycleRightRotate(int arr[], int n, int step) {
    int newArr[n] = {0};
    for(int i=0; i<n; i++) {
        newArr[(i+step)%n] = arr[i];
    }
    for(int i=0; i<n; i++) {
        cout<<newArr[i]<<" ";
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cycleRightRotate(arr, size, 2);
    return 0;
}