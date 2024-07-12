#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    vector<string> table[TABLE_SIZE];
    
    int hashFunction(string key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % TABLE_SIZE;
    }
    
    int quadraticProbe(int hashVal, int i) {
        return (hashVal + i*i) % TABLE_SIZE;
    }
    
public:
    void insert(string key) {
        int hashVal = hashFunction(key);
        int index = hashVal;
        int i = 1;
        while (!table[index].empty()) {
            index = quadraticProbe(hashVal, i);
            i++;
        }
        table[index].push_back(key);
    }
    
    bool search(string key) {
        int hashVal = hashFunction(key);
        int index = hashVal;
        int i = 1;
        while (!table[index].empty()) {
            if (table[index][0] == key) {
                return true;
            }
            index = quadraticProbe(hashVal, i);
            i++;
        }
        return false;
    }
    
    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "[" << i << "] ";
            for (string key : table[i]) {
                cout << key << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht;
    ht.insert("apple");
    ht.insert("banana");
    ht.insert("cherry");
    ht.insert("date");
    ht.insert("grape");
    
    cout << "HashTable after insertion:" << endl;
    ht.display();
    
    cout << "Searching for 'banana': " << (ht.search("banana") ? "Found" : "Not found") << endl;
    cout << "Searching for 'kiwi': " << (ht.search("kiwi") ? "Found" : "Not found") << endl;
    
    return 0;
}
