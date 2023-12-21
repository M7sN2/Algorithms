/*
 * Quick Sort Algorithm
 * 
 * Time Complexity:
 * - Best Case: O(n log n)
 * - Average Case: O(n log n)
 * - Worst Case: O(n²) - when pivot is always smallest/largest
 * 
 * Space Complexity: O(log n) - due to recursion
 * 
 * Divide and Conquer Algorithm
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

// Partition function - places pivot in correct position
int partition(vector<int>& arr, int low, int high) {
    // Choose the rightmost element as pivot
    int pivot = arr[high];
    
    // Index of smaller element (indicates right position of pivot)
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Place pivot in correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get pivot index
        int pi = partition(arr, low, high);
        
        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Test array
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array:" << endl;
    printArray(arr);
    
    
    // Sort the array
    quickSort(arr, 0, arr.size() - 1);
    
    cout << "\nSorted array:" << endl;
    printArray(arr);
    
    return 0;
}

