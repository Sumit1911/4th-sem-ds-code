#include<iostream>
using namespace std;

int SearchKey(int arr[], int key, int size) {
    for(int i=0; i<size; i++) {
        if(arr[i]==key) {
            return 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, -1, 5, 0, 8, 6};
    int key = 10;
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = SearchKey(arr, key, size);
    if(result == 1) {
        cout<<"Key Found!";
    } else {
        cout<<"Key not Found!";
    }
    return 0;
}