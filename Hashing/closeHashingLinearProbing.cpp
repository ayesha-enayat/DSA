
#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

struct HashTable {

    int table[TABLE_SIZE];
    bool isOccupied[TABLE_SIZE];

    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = -1; 
            isOccupied[i] = false;
        }
    }

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);

        while (isOccupied[index]) {
            index = (index + 1) % TABLE_SIZE; 
        }

        table[index] = key;
        isOccupied[index] = true;
    }

    int search(int key) {
        int index = hashFunction(key);

        while (isOccupied[index]) {
            if (table[index] == key) {
                return index; 
            }
            index = (index + 1) % TABLE_SIZE; 
        }

        return -1; 
    }
};

int main() {
    HashTable ht;
    
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    cout<<"enter value you want to search : " ;
    int searchKey ;
    cin>>searchKey;
    int result = ht.search(searchKey);
    if (result != -1) {
        cout << "Key " << searchKey << " found at index " << result << endl;
    } else {
        cout << "Key " << searchKey << " not found." << endl;
    }

    return 0;
}

