/*
 * Hash Table Implementation
 * 
 * Hash Table is a data structure that stores key-value pairs.
 * 
 * Collision Handling: Chaining (using linked lists)
 * 
 * Time Complexity (Average):
 * - Insert: O(1)
 * - Search: O(1)
 * - Delete: O(1)
 * 
 * Time Complexity (Worst):
 * - All operations: O(n) - when all keys hash to same index
 */

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 10;  // Size of hash table
    vector<list<pair<int, string>>> table;  // Hash table with chaining
    
    // Hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }
    
public:
    // Constructor
    HashTable() {
        table.resize(TABLE_SIZE);
    }
    
    // Insert a key-value pair
    void insert(int key, const string& value) {
        int index = hashFunction(key);
        
        // Check if key already exists
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;  // Update value
                return;
            }
        }
        
        // Insert new key-value pair
        table[index].push_back({key, value});
    }
    
    // Search for a key
    string search(int key) {
        int index = hashFunction(key);
        
        // Search in the chain
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        
        return "";  // Key not found
    }
    
    // Delete a key
    bool remove(int key) {
        int index = hashFunction(key);
        
        // Find and remove the key
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->first == key) {
                table[index].erase(it);
                return true;
            }
        }
        
        return false;  // Key not found
    }
    
    // Display the hash table
    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            if (table[i].empty()) {
                cout << "Empty";
            } else {
                for (const auto& pair : table[i]) {
                    cout << "(" << pair.first << ", " << pair.second << ") ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht;
    
    // Insert some key-value pairs
    ht.insert(1, "Ahmed");
    ht.insert(2, "Mohamed");
    ht.insert(11, "Ali");  // Will collide with key 1 (same hash)
    ht.insert(22, "Sara"); // Will collide with key 2 (same hash)
    ht.insert(5, "Fatima");
    
    // Display the hash table
    ht.display();
    
    // Search for a key
    cout << "\nSearching for key 11: " << ht.search(11) << endl;
    cout << "Searching for key 3: " << (ht.search(3).empty() ? "Not found" : ht.search(3)) << endl;
    
    // Remove a key
    cout << "\nRemoving key 2..." << endl;
    ht.remove(2);
    ht.display();
    
    return 0;
}
