#include<iostream>
#include<string>
using namespace std;

void merge(string str[], int s, int e) {
    int mid = (s+e)/2;
    int len1 = mid-s+1;  //length of str1
    int len2 = e-mid;    //length of str2

    string str1[len1], str2[len2];

    //copy values
    int mainStringIndex = s;
    for(int i=0; i<len1; i++) { //copy in first string
        str1[i] = str[mainStringIndex++];
    } 
    mainStringIndex = mid+1;
    for(int i=0; i<len2; i++) { //copy in second string
        str2[i] = str[mainStringIndex++];
    }

    //merge 2 sorted string
    int index1 = 0, index2 = 0;
    mainStringIndex = s;
    while (index1<len1 && index2<len2) {
        if(str1[index1]<str2[index2]) {
            str[mainStringIndex++] = str1[index1++];
        } else {
            str[mainStringIndex++] = str2[index2++];
        }
    }

    while(index1<len1) {  //rest element of str1
        str[mainStringIndex++] = str1[index1++];
    }
    while(index2<len2) {  //rest element of str2
        str[mainStringIndex++] = str2[index2++];
    }
    
}

void mergeSort(string str[], int s, int e) {
    if(s>=e) {
        return;
    }
    int mid = (s+e)/2;

    mergeSort(str, s, mid);
    mergeSort(str, mid+1, e);
    merge(str, s, e);
}

void printString(string str[], int size) {
    for (int i = 0; i <=size; i++) {
        cout << str[i] << " ";
    }
    cout << endl;
}

int main() {
    string str[] = {"banana", "apple", "orange", "grape", "kiwi", "strawberry"};
    int size = sizeof(str) / sizeof(str[0]);

    cout<<"Given array is : ";
    printString(str, size-1);

    mergeSort(str, 0, size - 1);

    cout<<"Sorted array is : ";
    printString(str, size-1);
    return 0;
}
