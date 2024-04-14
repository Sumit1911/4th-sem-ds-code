#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

vector<int> randomVector(int n, int upperBound) {
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % upperBound;
    }
    return vec;
}

void printVector(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        // cout << vec[i] << " ";
    }
    cout << endl;
}

int bubbleSort(vector<int>& arr) {
    int n = arr.size();
    int swap = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap++;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return swap;
}

int insertionSort(vector<int>& arr) {
    int n = arr.size();
    int swap = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            swap++;
        }
        arr[j + 1] = key;
    }
    return swap;
}

int selectionSort(vector<int>& arr) {
    int n = arr.size();
    int swap = 0;
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap++;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    return swap;
}

int main() {
    int numValues = 1000;
    int upperBound = 1000;
    vector<int> values = randomVector(numValues, upperBound);
    
    // cout << "Before sorting:" << endl;
    // printVector(values);
    
    // Bubble Sort
    vector<int> bubbleValues = values;
    auto bubble_start = high_resolution_clock::now();
    int bubble_swaps = bubbleSort(bubbleValues);
    auto bubble_stop = high_resolution_clock::now();
    auto bubble_duration = duration_cast<microseconds>(bubble_stop - bubble_start);
    
    // Insertion Sort
    vector<int> insertionValues = values;
    auto insertion_start = high_resolution_clock::now();
    int insertion_swaps = insertionSort(insertionValues);
    auto insertion_stop = high_resolution_clock::now();
    auto insertion_duration = duration_cast<microseconds>(insertion_stop - insertion_start);
    
    // Selection Sort
    vector<int> selectionValues = values;
    auto selection_start = high_resolution_clock::now();
    int selection_swaps = selectionSort(selectionValues);
    auto selection_stop = high_resolution_clock::now();
    auto selection_duration = duration_cast<microseconds>(selection_stop - selection_start);
    
    cout << "After sorting:" << endl;
    cout << "Bubble Sort - Time taken: " << bubble_duration.count() << " microseconds, Swaps: " << bubble_swaps << endl;
    cout << "Insertion Sort - Time taken: " << insertion_duration.count() << " microseconds, Swaps: " << insertion_swaps << endl;
    cout << "Selection Sort - Time taken: " << selection_duration.count() << " microseconds, Swaps: " << selection_swaps << endl;
    
    return 0;
}
