/*
 * Depth-First Search (DFS) Algorithm
 * 
 * Time Complexity: O(V + E)
 * where V = number of vertices, E = number of edges
 * 
 * Space Complexity: O(V)
 * 
 * DFS explores as far as possible along each branch before backtracking.
 */

#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list
    
    // DFS helper function (recursive)
    void DFSUtil(int v, vector<bool>& visited) {
        // Mark the current node as visited and print it
        visited[v] = true;
        cout << v << " ";
        
        // Recur for all adjacent vertices
        for (int u : adj[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }
    
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
    
    // DFS traversal starting from vertex v
    void DFS(int v) {
        // Mark all vertices as not visited
        vector<bool> visited(V, false);
        
        cout << "DFS Traversal starting from vertex " << v << ":" << endl;
        
        // Call the recursive helper function
        DFSUtil(v, visited);
        cout << endl;
    }
    
    // DFS for disconnected graph (visits all vertices)
    void DFSAll() {
        vector<bool> visited(V, false);
        
        cout << "DFS Traversal (all vertices):" << endl;
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited);
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
    
    // Perform DFS starting from vertex 0
    g.DFS(0);
    
    return 0;
}
