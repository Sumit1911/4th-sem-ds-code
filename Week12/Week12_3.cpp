#include<iostream>
using namespace std;

class Heap {
    public:
    int arr[100];
    int size;
    
    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2*i;
        int right = 2*i+1;

        if(left<=n && arr[largest]<arr[left]) {
            largest = left;
        }
        if(right<=n && arr[largest]<arr[right]) {
            largest = right;
        }
        
        if(largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    } 

    //max heap
    void heap_sort(int arr[], int n) {
        //1.buildHeap
        //2.swap first with last 
        //3.place root node at their correct position
        int size = n;
        while(size>1) {
            swap(arr[size], arr[1]);
            size--;
            heapify(arr, size, 1);
        }
    }
};

int main() {
    Heap h;
    int arr[] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i>0; i--) {
        h.heapify(arr, n, i);
    }

    cout<<"Printing the array : "<<endl;
    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    h.heap_sort(arr, n);
    cout<<"Printing the sorted array : "<<endl;
    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}