#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 10;

class HashNode {
public:
    int key;
    int value;
    HashNode(int key, int value) : key(key), value(value) {}
};

class HashMap {
private:
    vector<HashNode*> table;

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashMap() {
        table.assign(TABLE_SIZE, nullptr);
    }

    void insert(int key, int value) {
        int index = hashFunction(key);

        while (table[index] != nullptr && table[index]->key != key) {
            index = (index + 1) % TABLE_SIZE; 
        }

        if (table[index] != nullptr) {
            delete table[index];
        }

        table[index] = new HashNode(key, value);
    }

    int search(int key) {
        int index = hashFunction(key);

        while (table[index] != nullptr && table[index]->key != key) {
            index = (index + 1) % TABLE_SIZE; 
        }

        if (table[index] != nullptr && table[index]->key == key) {
            return table[index]->value;
        } else {
            return -1; // Key not found
        }
    }
};

int main() {
    HashMap hash;
    
    hash.insert(5, 100);
    hash.insert(15, 200);
    hash.insert(25, 300);
    
    cout << "Value for key 15: " << hash.search(15) << endl;
    cout << "Value for key 10: " << hash.search(10) << endl;

    return 0;
}
