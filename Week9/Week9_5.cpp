#include<iostream>
using namespace std;

void Heapify(int arr[], int i, int n) {
    int left = 2*i;
    int right = 2*i+1;
    int largest = i;
    if(left<=n && arr[largest]<arr[left]) {
        largest = left;
    }
    if(right<=n && arr[largest]<arr[right]) {
        largest = right;
    }
    if(i!=largest) {
        swap(arr[i], arr[largest]);
        Heapify(arr, largest, n);
    }
}


int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    Heapify(arr, 1, 7);
    for(int i=0; i<7; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}