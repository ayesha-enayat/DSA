#include<iostream>
using namespace std;

int main() {

    /*Array Input*/

    int size, i;
    cout << "Enter Number of Elements: ";
    cin >> size;

    int arr[size];

    for (i = 0; i < size; i++) {
        cout << "Enter Element : ";
        cin >> arr[i];
    }

    /*Sorting*/

    int temp, j, k;

    for (j = 0; j < size; j++) {
        for (k = j + 1; k < size; k++) {
            if (arr[j] > arr[k]) {
                temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
        cout << arr[j] << endl;
    }

    return 0;
}
