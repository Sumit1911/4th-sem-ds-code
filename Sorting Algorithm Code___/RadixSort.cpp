#include<iostream>
#include<cmath>
using namespace std;

void countingSort(int arr[], int size, int exp) {
    // Create a count array to store count of individual digits (0-9)
    int count[10] = {0};

    // Count the occurrences of each digit at the specified place value (exp)
    for (int i = 0; i < size; i++) {
        count[(arr[i]/exp) % 10]++;
    }

    // Modify the count array to store the sum of counts
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store sorted elements
    int output[size];
    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i]/exp) % 10] - 1] = arr[i];
        count[(arr[i]/exp) % 10]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

// Radix sort function
void radixSort(int arr[], int size) {
    int maxElem = arr[0];
    for(int i=0; i<size; i++) {
        if(arr[i]>maxElem) {
            maxElem = arr[i];
        }
    }
    // Perform counting sort for each digit place value (units, tens, hundreds, etc.)
    //exp parameter represents the exponent or the place value of the digit being considered during each pass of the counting sort algorithm.
    for (int exp = 1; maxElem/exp > 0; exp *= 10) {  
        countingSort(arr, size, exp);
    }
}

int main() {
    int arr[] = {804, 26, 5, 64, 52, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, size);

    cout << "Sorted array:";
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    cout << endl;

    return 0;
}
