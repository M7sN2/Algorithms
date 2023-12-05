/*
 * Bubble Sort Algorithm
 * 
 * Time Complexity:
 * - Best Case: O(n) - when array is already sorted
 * - Average Case: O(n²)
 * - Worst Case: O(n²)
 * 
 * Space Complexity: O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

// Function to print array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Bubble Sort Implementation
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    
    // Outer loop for passes
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        
        // Inner loop for comparisons
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap if they are in wrong order
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        // If no swapping occurred, array is sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    // Test array
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array:" << endl;
    printArray(arr);
    
    // Sort the array
    bubbleSort(arr);
    
    cout << "\nSorted array:" << endl;
    printArray(arr);
    
    return 0;
}

