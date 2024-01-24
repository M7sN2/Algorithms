/*
 * Sorting Algorithms Comparison Tool
 * 
 * This program compares different sorting algorithms by measuring
 * their execution time on arrays of various sizes.
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <iomanip>
using namespace std;
using namespace std::chrono;

// Function to generate random array
vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}

// Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1), rightArr(n2);
    
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Function to measure execution time
double measureTime(void (*sortFunc)(vector<int>&), vector<int> arr) {
    auto start = high_resolution_clock::now();
    sortFunc(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000.0;  // Convert to milliseconds
}

double measureTimeMerge(void (*sortFunc)(vector<int>&, int, int), vector<int> arr) {
    auto start = high_resolution_clock::now();
    sortFunc(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000.0;
}

double measureTimeQuick(void (*sortFunc)(vector<int>&, int, int), vector<int> arr) {
    auto start = high_resolution_clock::now();
    sortFunc(arr, 0, arr.size() - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000.0;
}

int main() {
    cout << "========================================" << endl;
    cout << "Sorting Algorithms Comparison Tool" << endl;
    cout << "========================================\n" << endl;
    
    // Test different array sizes
    vector<int> sizes = {100, 500, 1000, 5000, 10000};
    
    cout << setw(15) << "Array Size" << setw(15) << "Bubble" << setw(15) 
         << "Insertion" << setw(15) << "Selection" << setw(15) 
         << "Merge" << setw(15) << "Quick" << endl;
    cout << string(90, '-') << endl;
    
    for (int size : sizes) {
        vector<int> arr = generateRandomArray(size);
        
        double bubbleTime = measureTime(bubbleSort, arr);
        double insertionTime = measureTime(insertionSort, arr);
        double selectionTime = measureTime(selectionSort, arr);
        double mergeTime = measureTimeMerge(mergeSort, arr);
        double quickTime = measureTimeQuick(quickSort, arr);
        
        cout << setw(15) << size 
             << setw(15) << fixed << setprecision(2) << bubbleTime << " ms"
             << setw(15) << insertionTime << " ms"
             << setw(15) << selectionTime << " ms"
             << setw(15) << mergeTime << " ms"
             << setw(15) << quickTime << " ms" << endl;
    }
    
    cout << "\nNote: Times are in milliseconds (ms)" << endl;
    
    return 0;
}

