#include <algorithm>
#include <iostream>
#include <cstdlib>  
#include <chrono>
using namespace std;
using namespace std::chrono;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* randomArray(int n, int upperBound) {
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % upperBound;
    }
    return arr;
}

int main() {
    int numValues = 1000;
    int upperBound = 25;
    int* values = randomArray(numValues, upperBound);
    printArray(values, numValues);
    
    // Get starting timepoint
    auto start = high_resolution_clock::now();
    // Call the sort() function
    // sort(values, values + numValues); 
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
 
    // Subtract timepoints to get duration. 
    // To cast it to proper unit, use duration_cast() method
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    // printArray(values, numValues); // If you want to print sorted array

    // Free dynamically allocated memory
    delete[] values;
    
    return 0;
}
