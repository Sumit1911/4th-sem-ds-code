#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArray(int arr[], int size) {
    int temp;
    for(int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    int arr[] = {1, 3, 9, 23, -2, 34, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);
    reverseArray(arr, size);
    printArray(arr, size);

    return 0;
}
