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

    void max_heapify(int arr[], int n, int i) {
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
            max_heapify(arr, n, largest);
        }
    }

    int kth_smallest(int arr[], int size, int k) {
        for(int i=k/2; i>0; i--) {
            max_heapify(arr, size, i);
        }
        for(int i=k+1; i<=size; i++) {
            if(arr[i]<arr[1]) {
                arr[1] = arr[i];
                max_heapify(arr, k, 1);
            }
        }
        // return arr[1];
        cout<<"kth smallest element :"<<arr[1]<<endl;
    }
    
    void min_heapify(int arr[], int n, int i) {
        int smallest = i;
        int left = 2*i;
        int right = 2*i+1;

        if(left<=n && arr[smallest]>arr[left]) {
            smallest = left;
        }
        if(right<=n && arr[smallest]>arr[right]) {
            smallest = right;
        }
        if(smallest != i) {
            swap(arr[smallest], arr[i]);
            min_heapify(arr, n, smallest);
        }
    }

    int kth_largest(int arr[], int size, int k) {
        for(int i=k/2; i>0; i--) {
            min_heapify(arr, size, i);
        }
        for(int i=k+1; i<=size; i++) {
            if(arr[i]>arr[1]) {
                arr[1] = arr[i];
                min_heapify(arr, k, 1);
            }
        }
        // return arr[1];
        cout<<"kth largest element :"<<arr[1]<<endl;
    }
    
};

int main() {
    Heap h;
    int arr[] = {-1, 7, 10, 4, 20, 15};
    int n = 5;
    
    h.kth_smallest(arr, n, 4);
    h.kth_largest(arr, n, 4);

    return 0;
}