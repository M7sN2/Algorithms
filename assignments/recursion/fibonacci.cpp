/*
 * Fibonacci Sequence using Recursion
 * 
 * Fibonacci: F(n) = F(n-1) + F(n-2)
 * where F(0) = 0, F(1) = 1
 * 
 * Time Complexity: O(2^n) - exponential (inefficient)
 * Space Complexity: O(n) - due to recursion stack
 * 
 * Note: This is inefficient. Use Dynamic Programming for better performance.
 */

#include <iostream>
using namespace std;

// Recursive Fibonacci
int fibonacciRecursive(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    
    // Recursive case
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative Fibonacci (more efficient)
int fibonacciIterative(int n) {
    if (n <= 1) {
        return n;
    }
    
    int prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }
    
    return curr;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    
    cout << "\nFibonacci Sequence (Recursive):" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursive(i) << " ";
    }
    cout << endl;
    
    cout << "\nFibonacci Sequence (Iterative):" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibonacciIterative(i) << " ";
    }
    cout << endl;
    
    return 0;
}
