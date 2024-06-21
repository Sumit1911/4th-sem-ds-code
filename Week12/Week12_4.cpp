#include <iostream>
#include <string>
using namespace std;

class MaxHeap {
public:
    pair<char, int> heap[256];
    int size;

    MaxHeap() {
        size = 0;
    }

    void insert(pair<char, int> p) {
        size++;
        int index = size;
        heap[index] = p;

        while (index > 1 && heap[index].second > heap[index / 2].second) {
            swap(heap[index], heap[index / 2]);
            index = index / 2;
        }
    }

    pair<char, int> extractMax() {
        if (size == 0) {
            return {'#', -1};
        }

        pair<char, int> root = heap[1];
        heap[1] = heap[size];
        size--;

        heapify(1);
        return root;
    }

private:
    void heapify(int index) {
        int largest = index;
        int left = 2 * index;
        int right = 2 * index + 1;

        if (left <= size && heap[left].second > heap[largest].second) {
            largest = left;
        }
        if (right <= size && heap[right].second > heap[largest].second) {
            largest = right;
        }
        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapify(largest);
        }
    }
};

string sortStringByFrequency(string s) {
    // Step 1: Count frequency of each character
    int frequency[256] = {0};
    for (char c : s) {
        frequency[c]++;
    }

    // Step 2: Use a max-heap to sort characters by frequency
    MaxHeap maxHeap;
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            maxHeap.insert({(char)i, frequency[i]});
        }
    }

    // Step 3: Construct the output string
    string result;
    while (maxHeap.size > 0) {
        pair<char, int> p = maxHeap.extractMax();
        result.append(p.second, p.first);
    }

    return result;
}

int main() {
    string s = "tree";
    string sortedString = sortStringByFrequency(s);
    cout << "Sorted string by frequency: " << sortedString << endl;
    return 0;
}
