#include <iostream>
using namespace std;

void merge(int arr[], int s, int e) {
    int mid = (s+e)/2;
    int len1 = mid-s+1;  //length of arr1
    int len2 = e-mid;    //length of arr2

    int arr1[len1], arr2[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) { //copy in first array
        arr1[i] = arr[mainArrayIndex++];
    } 
    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) { //copy in second array
        arr2[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted array
    int index1 = 0, index2 = 0;
    mainArrayIndex = s;
    while (index1<len1 && index2<len2) {
        if(arr1[index1]<arr2[index2]) {
            arr[mainArrayIndex++] = arr1[index1++];
        } else {
            arr[mainArrayIndex++] = arr2[index2++];
        }
    }

    while(index1<len1) {  //rest element of arr1
        arr[mainArrayIndex++] = arr1[index1++];
    }
    while(index2<len2) {  //rest element of arr2
        arr[mainArrayIndex++] = arr2[index2++];
    }
    
}

void mergeSort(int arr[], int s, int e) {
    if(s>=e) {
        return;
    }
    int mid = (s+e)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, e);
}

void printArray(int arr[], int size) {
    for (int i = 0; i <=size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 11, 8, 5, -1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<"Given array is : ";
    printArray(arr, size-1);

    mergeSort(arr, 0, size - 1);

    cout<<"Sorted array is : ";
    printArray(arr, size-1);
    return 0;
}
