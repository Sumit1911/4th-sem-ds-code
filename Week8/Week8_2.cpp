#include <iostream>
using namespace std;

void reconstructQueue(int people[][2], int n) {
    for (int i = 0; i < n; ++i) {
        int count = people[i][1];
        for (int j = 0; j < n; ++j) {
            if (count == 0 && people[j][0] == -1) {
                people[j][0] = people[i][0];
                people[j][1] = people[i][1];
                break;
            } else if (people[j][0] == -1 || people[j][0] >= people[i][0]) {
                --count;
            }
        }
    }
}

int main() {
    int people[][2] = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    int n = sizeof(people) / sizeof(people[0]);
    
    reconstructQueue(people, n);
    
    cout << "Reconstructed Queue:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "(" << people[i][0] << ", " << people[i][1] << ") ";
    }
    cout << endl;

    return 0;
}
