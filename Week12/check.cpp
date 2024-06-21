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
            heapify(arr, n, smallest);
        }
    }

    int kth_largest(int arr[], int size, int k) {
        for(int i=k/2; i>0; i--) {
            heapify(arr, size, i);
        }
        for(int i=k+1; i<=size; i++) {
            if(arr[i]>arr[1]) {
                arr[1] = arr[i];
                heapify(arr, k, 1);
            }
        }
        // return arr[1];
        cout<<"kth smallest element :"<<arr[1];
    }
    
    // int kth_smallest(int arr[], int size, int k) {
        
    // }
};

int main() {
    Heap h;
    int arr[] = {-1, 7, 10, 4, 20, 15};
    int n = 5;
    
    // h.kth_smallest(arr, n, 4);
    // for(int i=n/2; i>0; i--) {
    //     h.heapify(arr, n, i);
    // }
    // for(int i=1; i<=n; i++) {
    //     cout<<arr[i]<<" ";
    // }
    h.kth_largest(arr, n, 4);

    return 0;
}