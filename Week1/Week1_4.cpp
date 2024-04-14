#include<iostream>
using namespace std;

int intersectionOfArr(int arr1[], int arr2[], int size1, int size2) {
    int newArr[size1] = {0};
    int index = 0;
    for(int i=0; i<size1; i++) {
        for(int j=0; j<size2; j++) {
            if(arr1[i] == arr2[j]) {
                newArr[index] = arr1[i];
                index++;
            }
        }
    }
    for(int i=0; i<index; i++) {
        cout<<newArr[i]<<" ";
    }
}

int main() {
    int arr1[] = {1, 2, 5, 6, 8, 7};
    int arr2[] = {1, 77, 3, 7, 0, 3};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    intersectionOfArr(arr1, arr2, size1, size2);
    return 0;
}