
#include<iostream>
using namespace std;

int main() {
    int size, i;
    cout << "Enter Number of Elements: ";
    cin >> size;

    int arr[size];

    for (i = 0; i < size; i++) {
        cout << "Enter Element : ";
        cin >> arr[i];
    }

    int temp, j, k, min_i;

    for (j = 0; j < size; j++) {
        min_i = j;
        for (k = j + 1; k < size; k++) {
            if (arr[k] < arr[min_i]) {
                min_i = k;
            }
        }
        temp = arr[j];
        arr[j] = arr[min_i];
        arr[min_i] = temp;

        cout << arr[j] << endl;
    }

    return 0;
}
