/*
 * Dijkstra's Algorithm for Shortest Path
 * 
 * Dijkstra's algorithm finds the shortest path from a source vertex
 * to all other vertices in a weighted graph.
 * 
 * Time Complexity: O(V²) for adjacency matrix, O((V+E)log V) for adjacency list
 * Space Complexity: O(V)
 */

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

class Graph {
private:
    int V;  // Number of vertices
    vector<vector<int>> adjMatrix;  // Adjacency matrix
    
public:
    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));
    }
    
    // Add an edge with weight
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;  // For undirected graph
    }
    
    // Find vertex with minimum distance
    int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
        int min = INT_MAX, minIndex = -1;
        
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        }
        
        return minIndex;
    }
    
    // Print the solution
    void printSolution(const vector<int>& dist, int src) {
        cout << "\nShortest distances from vertex " << src << ":" << endl;
        cout << "Vertex\tDistance" << endl;
        cout << "-------------------" << endl;
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                cout << i << "\tInfinity" << endl;
            } else {
                cout << i << "\t" << dist[i] << endl;
            }
        }
    }
    
    // Dijkstra's algorithm
    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);  // Shortest distances
        vector<bool> sptSet(V, false);  // Shortest path tree set
        
        dist[src] = 0;  // Distance from source to itself is 0
        
        // Find shortest path for all vertices
        for (int count = 0; count < V - 1; count++) {
            // Pick the minimum distance vertex
            int u = minDistance(dist, sptSet);
            
            // Mark the picked vertex as processed
            sptSet[u] = true;
            
            // Update distances of adjacent vertices
            for (int v = 0; v < V; v++) {
                if (!sptSet[v] && adjMatrix[u][v] != 0 && 
                    dist[u] != INT_MAX && 
                    dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }
        
        printSolution(dist, src);
    }
};

int main() {
    // Create a graph
    Graph g(6);
    
    // Add edges with weights
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 10);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 6);
    g.addEdge(4, 5, 3);
    
    cout << "Dijkstra's Algorithm" << endl;
    cout << "========================================" << endl;
    
    // Find shortest paths from vertex 0
    g.dijkstra(0);
    
    return 0;
}

