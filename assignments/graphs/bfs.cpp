/*
 * Breadth-First Search (BFS) Algorithm
 * 
 * Time Complexity: O(V + E)
 * where V = number of vertices, E = number of edges
 * 
 * Space Complexity: O(V)
 * 
 * BFS visits all nodes at the current depth before moving to the next level.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list
    
public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    
    // Add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // For undirected graph
    }
    
    // BFS traversal starting from vertex s
    void BFS(int s) {
        // Mark all vertices as not visited
        vector<bool> visited(V, false);
        
        // Create a queue for BFS
        queue<int> q;
        
        // Mark the current node as visited and enqueue it
        visited[s] = true;
        q.push(s);
        
        cout << "BFS Traversal starting from vertex " << s << ":" << endl;
        
        while (!q.empty()) {
            // Dequeue a vertex and print it
            int u = q.front();
            q.pop();
            cout << u << " ";
            
            // Get all adjacent vertices
            for (int v : adj[u]) {
                // If adjacent vertex is not visited, mark it and enqueue it
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Create a graph
    Graph g(6);
    
    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    
    // Perform BFS starting from vertex 0
    g.BFS(0);
    
    return 0;
}
