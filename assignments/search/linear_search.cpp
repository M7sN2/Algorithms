/*
 * Linear Search Algorithm
 * 
 * Time Complexity:
 * - Best Case: O(1) - when element is at first position
 * - Average Case: O(n)
 * - Worst Case: O(n) - when element is at last position or not found
 * 
 * Space Complexity: O(1)
 * 
 * No requirement for sorted array
 */

#include <iostream>
#include <vector>
using namespace std;

// Linear Search function
int linearSearch(const vector<int>& arr, int target) {
    // Traverse through all elements
    for (int i = 0; i < arr.size(); i++) {
        // If target is found, return index
        if (arr[i] == target) {
            return i;
        }
    }
    
    // Element not found
    return -1;
}

int main() {
    // Array (doesn't need to be sorted)
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int target = 25;
    
    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Searching for: " << target << endl;
    
    int result = linearSearch(arr, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}
