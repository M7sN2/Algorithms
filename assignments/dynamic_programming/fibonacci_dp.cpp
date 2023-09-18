/*
 * Fibonacci using Dynamic Programming (Memoization)
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * Much more efficient than naive recursion O(2^n)
 */

#include <iostream>
#include <vector>
using namespace std;

// Fibonacci using Memoization (Top-Down DP)
int fibonacciMemo(int n, vector<int>& memo) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    
    // If already computed, return stored value
    if (memo[n] != -1) {
        return memo[n];
    }
    
    // Compute and store in memo
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    return memo[n];
}

// Fibonacci using Tabulation (Bottom-Up DP)
int fibonacciTab(int n) {
    if (n <= 1) {
        return n;
    }
    
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    // Fill the table
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    return dp[n];
}

// Fibonacci optimized (space-efficient)
int fibonacciOptimized(int n) {
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
    cout << "Enter n to find F(n): ";
    cin >> n;
    
    // Memoization approach
    vector<int> memo(n + 1, -1);
    cout << "\nFibonacci using Memoization:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "F(" << i << ") = " << fibonacciMemo(i, memo) << endl;
    }
    
    // Tabulation approach
    cout << "\nFibonacci using Tabulation:" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "F(" << i << ") = " << fibonacciTab(i) << endl;
    }
    
    // Optimized approach
    cout << "\nFibonacci (Optimized):" << endl;
    for (int i = 0; i <= n; i++) {
        cout << "F(" << i << ") = " << fibonacciOptimized(i) << endl;
    }
    
    return 0;
}

