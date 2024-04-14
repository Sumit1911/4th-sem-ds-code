#include <iostream>
#include <limits> 
using namespace std;

int main() {
    int arr[] = {1, 3, 9, 23, -2, 34, 5};
    int smallest = arr[0];
    int largest = arr[0];
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i < size; ++i) {
        if (smallest > arr[i]) {
            smallest = arr[i];
        }
        if (largest < arr[i]) {
            largest = arr[i];
        }
    }

    cout << "Smallest is: " << smallest << endl;
    cout << "Largest is: " << largest << endl;

    return 0;
}
