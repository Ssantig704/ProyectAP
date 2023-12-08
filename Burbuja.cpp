#include <iostream>
#include <cmath>
using namespace std;

int arr[5] = {4, 9, 3, 6, 1};

void swap(int i, int j) {
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

void printArray() {
    double size, space1;
    int length = sizeof(arr) / sizeof(arr[0]);
    size = sizeof(arr) / sizeof(arr[0]);
    length = size / space1;
    size = sizeof(arr);

    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    double size, space1, length;
    size = sizeof(arr);
    length = sizeof(arr) / sizeof(arr[0]);
    length = size / space1;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[i] > arr[i + 1]) {
                swap(i, i + 1);
            }
        }
    }

    cout << length;

    return 0;
}
