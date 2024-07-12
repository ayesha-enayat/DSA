#include <iostream>
using namespace std;

int main() {
    int length;
    cout << "Enter number of Elements : ";
    cin >> length;

    int ele[length];

    for(int i = 0; i < length; i++){
        cout << "Enter Element : ";
        cin >> ele[i];
    }

    int tosearch;
    cout << "Enter Search Value : ";
    cin >> tosearch;

    int L = 0;
    int R = length - 1;
    int flag = 0;

    while(L <= R) {
        int MP = (R + L) / 2;
        if(tosearch == ele[MP]) {
            cout << "Value found at index " << MP;
            flag = 1;
            break;
        } else {
            if(tosearch > ele[MP]) {
                L = MP + 1;
            } else {
                R = MP - 1;
            }
        }
    }

    if(flag == 0) {
        cout << "Value not found";
    }

    return 0;
}
