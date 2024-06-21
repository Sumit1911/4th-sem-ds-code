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

    void insert(int val) {
        size = size+1;
        int index = size;
        arr[index] = val;

        while (index>1) {
            int parent = index/2;
            if(arr[parent]>arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        } 
    }
    void print() {
        for(int i=1; i<=size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap() {
        if(size == 0) {
            cout<<"Nothing to delete"<<endl;
            return;
        }
        //step1: put last element into first
        arr[1] = arr[size];
        size--;  //step2: remove last node

        //step2: take root node to its correct position
        int i = 1;
        while(i<size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex<size && arr[i]>arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if(rightIndex<size && arr[i]>arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else {
                return;
            }
        }
    }

    void heapify(int arr[], int n, int i) {
        int smallest = i;
        int left = 2*i+1;
        int right = 2*i+2;

        if(left<=n && arr[smallest] > arr[left]) {
            smallest = left;
        } 
        if(right<=n && arr[smallest] > arr[right]) {
            smallest = right;
        }

        if(smallest != i ) {
            swap(arr[smallest], arr[i]);
            heapify(arr, n, smallest);
        }
    }

     void increaseKey(int i, int new_val) {
        if (i > size || i < 1) {
            cout << "Index out of bounds" << endl;
            return;
        }

        arr[i] = new_val;
        heapify(arr, size, i - 1); // Adjust to zero-based index for heapify
    }

    void decreaseKey(int i, int new_val) {
        if (i > size || i < 1) {
            cout << "Index out of bounds" << endl;
            return;
        }

        arr[i] = new_val;
        while (i > 1 && arr[i / 2] > arr[i]) {
            swap(arr[i], arr[i / 2]);
            i = i / 2;
        }
    }
};

int main() {
    Heap h;
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(10);
    cout<<"Heap : ";
    h.print();
    
    cout<<"Heap after delete the root node : ";
    h.deleteFromHeap();
    h.print();
    cout<<"*****************************"<<endl;

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i=n/2-1; i>0; i--){
       h.heapify(arr, n, i);
    }
    cout<<"Printing the array now "<<endl;

    for(int i=1; i<=n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    h.decreaseKey(3, 5);
    cout << "After decreasing key at index 3 to 5:" << endl;
    h.print();

    h.increaseKey(2, 45);
    cout << "After increasing key at index 2 to 45:" << endl;
    h.print();

    return 0;
}