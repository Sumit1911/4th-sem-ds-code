#include<iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int key, int ocr) {
  if(l>r) {
    return -1;
  }
  int mid = (l+r)/2;
  if(key == arr[mid]) {
    if(ocr<mid) {
      while (key!=arr[ocr]) {
        ocr++;
      }
    } else {
      while (key!=arr[ocr]) {
        ocr--;
      }
    }
    return ocr;
  } else if(key < arr[mid]) {
    binarySearch(arr, l, mid-1, key, ocr);
  } else {
    binarySearch(arr, mid+1, r, key, ocr);
  }
}

int main() {
    int arr[] = {3, 4, 4, 4, 5, 5, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 4;
    int first = 0, last = size - 1;
    cout<<"First Occurrence of key : ";
    cout<<binarySearch(arr, 0, size-1, key, first);
    cout<<endl<<"Last Occurrence of key : ";
    cout<<binarySearch(arr, 0, size-1, key, last);
    return 0;
}