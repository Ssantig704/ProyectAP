/*
Pointer Application
Created by: Santiago Octavio Garcia Mtz & Ricardo Lupercio Almaras
Date: 1/09/2023
*/
#include <iostream>

using namespace std;  // Use the std namespace

int main() {
    
    int num = 5;
    int* dynamic_arr = new int[num] {2, 4, 8, 9, 12};

    // The sum of the first and last number
    cout << "The sum is: " << *dynamic_arr + *(dynamic_arr + (num - 1)) << endl;
    cout << "The subtraction of the penultimate minus the second is: " << *(dynamic_arr + num - 2) - dynamic_arr[1] << endl;

    cout << "Multiplication * 10:\n";

    for (int i = 0; i < num; i++) {
        cout << "value: " << *(dynamic_arr + i) * 10 << "\n";
    }

    delete[] dynamic_arr;  // Free dynamically allocated memory

    return 0;
}
