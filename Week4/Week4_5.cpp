#include<iostream>
using namespace std;

void partition(int arr[], int s, int e, int &lessEnd, int &greaterStart) {
    int pivot = arr[s];
    int less = s;
    int greater = e;
    int i = s;

    while (i <= greater) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[less]);
            less++;
            i++;
        }
        else if (arr[i] > pivot) {
            swap(arr[i], arr[greater]);
            greater--;
        }
        else {
            i++;
        }
    }

    lessEnd = less - 1;
    greaterStart = greater + 1;
}

void QuickSort(int arr[], int s, int e) {
    if (s >= e) {
        return;
    }

    int lessEnd, greaterStart;
    partition(arr, s, e, lessEnd, greaterStart);

    QuickSort(arr, s, lessEnd);
    QuickSort(arr, greaterStart, e);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {38, 27, 27, 43, 3, 9, 3, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array : ";
    printArray(arr, size);

    QuickSort(arr, 0, size - 1);

    cout << "Sorted Array : ";
    printArray(arr, size);

    return 0;
}
