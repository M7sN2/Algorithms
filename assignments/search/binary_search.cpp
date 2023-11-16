/*
 * Binary Search Algorithm
 * 
 * Time Complexity:
 * - Best Case: O(1) - when element is at middle
 * - Average Case: O(log n)
 * - Worst Case: O(log n)
 * 
 * Space Complexity: O(1) - iterative, O(log n) - recursive
 * 
 * Requirement: Array must be sorted
 */

#include <iostream>
#include <vector>
using namespace std;

// Iterative Binary Search
int binarySearchIterative(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if target is at middle
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target is greater, ignore left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    
    // Element not found
    return -1;
}

// Recursive Binary Search
int binarySearchRecursive(const vector<int>& arr, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if target is at middle
        if (arr[mid] == target) {
            return mid;
        }
        
        // If target is smaller, search in left half
        if (arr[mid] > target) {
            return binarySearchRecursive(arr, target, left, mid - 1);
        }
        
        // If target is greater, search in right half
        return binarySearchRecursive(arr, target, mid + 1, right);
    }
    
    // Element not found
    return -1;
}

int main() {
    // Sorted array (required for binary search)
    vector<int> arr = {11, 12, 22, 25, 34, 64, 90};
    int target = 25;
    
    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    cout << "Searching for: " << target << endl;
    
    // Iterative search
    int result1 = binarySearchIterative(arr, target);
    if (result1 != -1) {
        cout << "Element found at index (Iterative): " << result1 << endl;
    } else {
        cout << "Element not found (Iterative)" << endl;
    }
    
    // Recursive search
    int result2 = binarySearchRecursive(arr, target, 0, arr.size() - 1);
    if (result2 != -1) {
        cout << "Element found at index (Recursive): " << result2 << endl;
    } else {
        cout << "Element not found (Recursive)" << endl;
    }
    
    return 0;
}
