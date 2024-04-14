#include<iostream>
#include<cmath>
using namespace std;

void countingSort(int arr[], int size, int exp) {
    const int base = 10; //base for decimal no.
    int count[19] = {0}; //range (-9 to 9)

    for (int i = 0; i < size; i++) {
        int digit = (arr[i]/exp)%base;
        count[digit+9]++;
    }

    for (int i = 1; i < 19; i++) {
        count[i] += count[i - 1];
    }

    int output[size];
    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i]/exp)%base;
        output[count[digit+9] - 1] = arr[i];
        count[digit+9]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int size) {
    int maxElem = arr[0];
    for(int i=0; i<size; i++) {
        if(arr[i]>maxElem) {
            maxElem = arr[i];
        }
    }

    for (int exp = 1; maxElem/exp > 0; exp *= 10) {  
        countingSort(arr, size, exp);
    }
}

int main() {
    int arr[] = {804, 26, 5, -64, -52, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, size);

    cout << "Sorted array:";
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i];
    }
    cout << endl;


    return 0;
}
