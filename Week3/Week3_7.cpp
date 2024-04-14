#include <iostream>
using namespace std;

void countingSort(int arr[], int size, int range) {
    // Create a count array to store count of individual elements
    int count[range] = {0};

    // Count the occurrences of each element in the input array
    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    // Modify the count array to store the sum of counts
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store sorted elements
    int output[size];
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void countingSortCharacters(char ch[], int size, int range) {
    int count[range] = {0};

    for(int i=0;i <size; i++) {
        count[ch[i] - 'a']++;
    }

    for(int i=1; i<range; i++) {
        count[i] += count[i-1];
    }

    char output[size];
    for(int i=size-1; i>=0; i--) {
        output[count[ch[i] - 'a']-1] = ch[i];
        count[ch[i] - 'a']--;
    }
    for(int i=0; i<size; i++) {
        ch[i] = output[i];
    }
}

template <typename T>
void displayArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {2, 2, 3, 4, 1, 5, 1, 5}; // Range: (1-5)
    int size = sizeof(arr) / sizeof(arr[0]);
    int range = 6; // Considering the range (1-5), plus 1 for the extra index
    
    cout<<"Unsorted Integers : "; displayArray(arr, size);
    countingSort(arr, size, range);
    cout<<"Sorted Integers : "; displayArray(arr, size);

    char ch[] = {'c', 'a', 'd', 'c', 'a', 'e'};
    int sizeCh = sizeof(ch)/sizeof(ch[0]);
    int rangeCh = 5; //range (a-e)
 
    cout<<"Sorted Characters : "; displayArray(ch, sizeCh);
    countingSortCharacters(ch, sizeCh, rangeCh);
    cout<<"Sorted Characters : "; displayArray(ch, sizeCh);

    return 0;
}
