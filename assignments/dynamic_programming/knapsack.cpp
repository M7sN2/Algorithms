/*
 * 0/1 Knapsack Problem using Dynamic Programming
 * 
 * Problem: Given weights and values of n items, put these items in a knapsack
 * of capacity W to get the maximum total value.
 * 
 * Time Complexity: O(n * W) where n = number of items, W = capacity
 * Space Complexity: O(n * W)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 0/1 Knapsack using Dynamic Programming
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    // Create a 2D DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            // If current item's weight is more than capacity, skip it
            if (weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            }
            // Otherwise, take maximum of including or excluding the item
            else {
                dp[i][w] = max(
                    dp[i - 1][w],  // Don't include current item
                    values[i - 1] + dp[i - 1][w - weights[i - 1]]  // Include current item
                );
            }
        }
    }
    
    return dp[n][W];
}

// Space-optimized version (using 1D array)
int knapsackOptimized(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<int> dp(W + 1, 0);
    
    for (int i = 0; i < n; i++) {
        // Traverse backwards to avoid using updated values
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }
    
    return dp[W];
}

int main() {
    // Example: Items with weights and values
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;  // Knapsack capacity
    int n = values.size();
    
    cout << "Knapsack Problem" << endl;
    cout << "Capacity: " << W << endl;
    cout << "\nItems:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": Weight = " << weights[i] 
             << ", Value = " << values[i] << endl;
    }
    
    int maxValue = knapsack(W, weights, values, n);
    cout << "\nMaximum value (2D DP): " << maxValue << endl;
    
    int maxValueOpt = knapsackOptimized(W, weights, values, n);
    cout << "Maximum value (Optimized): " << maxValueOpt << endl;
    
    return 0;
}

