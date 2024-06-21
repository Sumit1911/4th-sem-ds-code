#include <iostream>
using namespace std;

// MaxHeap class for the lower half
class MaxHeap {
public:
    int arr[1000];
    int size;

    MaxHeap() {
        size = 0;
    }

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        // Heapify up
        while (index > 1 && arr[index] > arr[index / 2]) {
            swap(arr[index], arr[index / 2]);
            index = index / 2;
        }
    }

    int extractMax() {
        if (size == 0) return -1;

        int maxVal = arr[1];
        arr[1] = arr[size];
        size--;

        // Heapify down
        heapify(1);
        return maxVal;
    }

    int getMax() {
        if (size == 0) return -1;
        return arr[1];
    }

private:
    void heapify(int index) {
        int largest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left <= size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right <= size && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(arr[largest], arr[index]);
            heapify(largest);
        }
    }
};

// MinHeap class for the upper half
class MinHeap {
public:
    int arr[1000];
    int size;

    MinHeap() {
        size = 0;
    }

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

        // Heapify up
        while (index > 1 && arr[index] < arr[index / 2]) {
            swap(arr[index], arr[index / 2]);
            index = index / 2;
        }
    }

    int extractMin() {
        if (size == 0) return -1;

        int minVal = arr[1];
        arr[1] = arr[size];
        size--;

        // Heapify down
        heapify(1);
        return minVal;
    }

    int getMin() {
        if (size == 0) return -1;
        return arr[1];
    }

private:
    void heapify(int index) {
        int smallest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left <= size && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if (right <= size && arr[right] < arr[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            swap(arr[smallest], arr[index]);
            heapify(smallest);
        }
    }
};

// Median class using MaxHeap and MinHeap
class MedianFinder {
private:
    MaxHeap maxHeap; // lower half
    MinHeap minHeap; // upper half

public:
    void addNum(int num) {
        // Add to max heap first
        if (maxHeap.size == 0 || num <= maxHeap.getMax()) {
            maxHeap.insert(num);
        } else {
            minHeap.insert(num);
        }

        // Balance the heaps
        if (maxHeap.size > minHeap.size + 1) {
            minHeap.insert(maxHeap.extractMax());
        } else if (minHeap.size > maxHeap.size) {
            maxHeap.insert(minHeap.extractMin());
        }
    }

    double findMedian() {
        if (maxHeap.size == minHeap.size) {
            return (maxHeap.getMax() + minHeap.getMin()) / 2.0;
        } else {
            return maxHeap.getMax();
        }
    }
};

int main() {
    MedianFinder mf;

    mf.addNum(10);
    mf.addNum(20);
    cout << "Median: " << mf.findMedian() << endl; // Output: 15

    mf.addNum(30);
    cout << "Median: " << mf.findMedian() << endl; // Output: 20

    mf.addNum(40);
    mf.addNum(50);
    cout << "Median: " << mf.findMedian() << endl; // Output: 30

    return 0;
}
