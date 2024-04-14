#include<iostream>
#include<cmath>
#include<cstring>
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


void countingSortStrings(string str[], int size, int exp) {
    // Create a count array to store count of individual characters (0-255)
    int count[256] = {0}; //Assuming ASCII characters

    // Count the occurrences of each characters at the specified place value (exp)
    for (int i = 0; i < size; i++) {
        count[str[i][exp]]++;
    }

    // Modify the count array to store the sum of counts
    for (int i = 1; i < 256; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store sorted elements
    string output[size];
    for (int i = size - 1; i >= 0; i--) {
        output[count[str[i][exp]] - 1] = str[i];
        count[str[i][exp]]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < size; i++) {
        str[i] = output[i];
    }  
}

// Radix sort function
void radixSortString(string str[], int size) {
    string maxElem = str[0];
    int maxLength = str[0].length();
    for(int i=1; i<size; i++) {
        if(maxLength == str[i].length()) {
            if(maxElem.compare(str[i])<0) {
                maxElem = str[i];
            }
        }
        if(maxLength<str[i].length()) {
            maxLength = str[i].length();
            maxElem = str[i];
        }
    }

    // for(int i=0; i<size; i++) {  //padding each string
    //     if(str[i].length() != maxLength) {
    //         str[i] = string(maxLength-str[i].length(), '0') + str[i];
    //     }
    // }

    // Perform counting sort for each digit place value (units, tens, hundreds, etc.)
    //exp parameter represents the exponent or the place value of the digit being considered during each pass of the counting sort algorithm.
    for (int exp = maxLength; exp >= 0; exp--) {  
        countingSortStrings(str, size, exp);
    }
}

template <typename T>
void displayArray(T arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {804, 26, 5, 64, 52, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array:"; displayArray(arr, size);
    radixSort(arr, size);
    cout << "Sorted array:"; displayArray(arr, size);


    string str[] = {"abd", "cde", "da", "a", "ab"};
    int sizeStr = sizeof(str)/sizeof(str[0]);
    cout<<"Unsorted string:"; displayArray(str, sizeStr);
    radixSortString(str, sizeStr);
    cout<<"Sorted string:"; displayArray(str, sizeStr);


    return 0;
}
