#include<iostream>
using namespace std;
int main() {
    int length;
    cout << "Enter number of Elements : ";
    cin >> length;

    int ele[length];

    for(int i = 0; i < length; i++) {
        cout << "Enter Element : ";
        cin >> ele[i];
    }

    int tosearch;
    cout << "Enter Search Value : ";
    cin >> tosearch;

    int flag = 0;

    for(int j = 0; j < length; j++) {
        if(ele[j] == tosearch) {
            cout << "Value found at index " << j;
            flag = 1;
        }
    }

    if(flag == 0) {
        cout << "Value not found";
    }

    return 0;
}
