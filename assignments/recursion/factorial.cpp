/*
 * Factorial using Recursion
 * 
 * Factorial: n! = n * (n-1) * (n-2) * ... * 1
 * where 0! = 1, 1! = 1
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n) - due to recursion stack
 */

#include <iostream>
using namespace std;

// Recursive Factorial
long long factorialRecursive(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }
    
    // Recursive case
    return n * factorialRecursive(n - 1);
}

// Iterative Factorial (more efficient)
long long factorialIterative(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers" << endl;
        return 1;
    }
    
    cout << "\nFactorial (Recursive): " << factorialRecursive(n) << endl;
    cout << "Factorial (Iterative): " << factorialIterative(n) << endl;
    
    return 0;
}
