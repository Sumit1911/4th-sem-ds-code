#include <iostream>
using namespace std;

void searchInSorted2DArray(int arr[][4], int rows, int cols, int target, int &comparisonsRow, int &comparisonsCol) {
    if (rows == 0 || cols == 0) {
        comparisonsRow = -1;
        comparisonsCol = -1;
        return;
    }

    int row = 0, col = cols - 1; // Start from top-right corner
    comparisonsRow = 0;
    comparisonsCol = 0;

    while (row < rows && col >= 0) {
        comparisonsRow++;
        comparisonsCol++;

        if (arr[row][col] == target) {
            return;
        } else if (arr[row][col] < target) {
            // Move to next row
            row++;
        } else {
            // Move to previous column
            col--;
        }
    }

    // Target not found
    comparisonsRow = -1;
    comparisonsCol = -1;
}

int main() {
    int arr[][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8}};
    int rows = sizeof(arr) / sizeof(arr[0]); // Number of rows
    int cols = sizeof(arr[0]) / sizeof(arr[0][0]); // Number of columns

    int target = 7;
    int comparisonsRow, comparisonsCol;
    searchInSorted2DArray(arr, rows, cols, target, comparisonsRow, comparisonsCol);

    if (comparisonsRow != -1 && comparisonsCol != -1) {
        cout << "Comparisons for row-based search: " << comparisonsRow << endl;
        cout << "Comparisons for column-based search: " << comparisonsCol << endl;
    } else {
        cout << "Target not found!" << endl;
    }

    return 0;
}
