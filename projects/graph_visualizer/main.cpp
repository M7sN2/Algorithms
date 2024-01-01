/*
 * Simple Graph Visualizer
 * برنامج تصور الرسوم البيانية البسيط
 * 
 * This program provides a simple text-based visualization of graphs
 * and demonstrates BFS and DFS traversals.
 * 
 * هذا البرنامج يوفر تصوراً نصياً بسيطاً للرسوم البيانية
 * ويوضح اجتياز BFS و DFS.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;

class Graph {
private:
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list
    
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    
    // Add an edge
    // إضافة حافة
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }
    
    // Print adjacency list
    // طباعة قائمة الجوار
    void printAdjacencyList() {
        cout << "\nAdjacency List / قائمة الجوار:" << endl;
        cout << "================================" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " / العقدة " << i << ": ";
            for (int v : adj[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    
    // Print adjacency matrix
    // طباعة مصفوفة الجوار
    void printAdjacencyMatrix() {
        vector<vector<int>> matrix(V, vector<int>(V, 0));
        
        for (int i = 0; i < V; i++) {
            for (int v : adj[i]) {
                matrix[i][v] = 1;
            }
        }
        
        cout << "\nAdjacency Matrix / مصفوفة الجوار:" << endl;
        cout << "===================================" << endl;
        cout << "   ";
        for (int i = 0; i < V; i++) {
            cout << setw(3) << i;
        }
        cout << endl;
        
        for (int i = 0; i < V; i++) {
            cout << setw(3) << i;
            for (int j = 0; j < V; j++) {
                cout << setw(3) << matrix[i][j];
            }
            cout << endl;
        }
    }
    
    // BFS Traversal
    // اجتياز BFS
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        
        cout << "\nBFS Traversal starting from " << start 
             << " / اجتياز BFS بدءاً من " << start << ":" << endl;
        cout << "===========================================" << endl;
        
        visited[start] = true;
        q.push(start);
        
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            cout << "Level " << level << " / المستوى " << level << ": ";
            
            for (int i = 0; i < size; i++) {
                int u = q.front();
                q.pop();
                cout << u << " ";
                
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            cout << endl;
            level++;
        }
    }
    
    // DFS Traversal
    // اجتياز DFS
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;
        
        cout << "\nDFS Traversal starting from " << start 
             << " / اجتياز DFS بدءاً من " << start << ":" << endl;
        cout << "===========================================" << endl;
        cout << "Order / الترتيب: ";
        
        s.push(start);
        
        while (!s.empty()) {
            int u = s.top();
            s.pop();
            
            if (!visited[u]) {
                visited[u] = true;
                cout << u << " ";
                
                // Push neighbors in reverse order to maintain left-to-right traversal
                // إضافة الجيران بترتيب عكسي للحفاظ على الاجتياز من اليسار لليمين
                for (int i = adj[u].size() - 1; i >= 0; i--) {
                    int v = adj[u][i];
                    if (!visited[v]) {
                        s.push(v);
                    }
                }
            }
        }
        cout << endl;
    }
    
    // Visual representation of graph
    // تمثيل مرئي للرسم البياني
    void visualize() {
        cout << "\nGraph Visualization / تصور الرسم البياني:" << endl;
        cout << "=========================================" << endl;
        
        for (int i = 0; i < V; i++) {
            cout << "[" << i << "]";
            if (!adj[i].empty()) {
                cout << " -> ";
                for (int j = 0; j < adj[i].size(); j++) {
                    cout << adj[i][j];
                    if (j < adj[i].size() - 1) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "========================================" << endl;
    cout << "Simple Graph Visualizer" << endl;
    cout << "برنامج تصور الرسوم البيانية البسيط" << endl;
    cout << "========================================" << endl;
    
    // Create a sample graph
    // إنشاء رسم بياني نموذجي
    Graph g(7);
    
    // Add edges
    // إضافة حواف
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    
    // Display graph representations
    // عرض تمثيلات الرسم البياني
    g.visualize();
    g.printAdjacencyList();
    g.printAdjacencyMatrix();
    
    // Perform traversals
    // تنفيذ الاجتيازات
    g.BFS(0);
    g.DFS(0);
    
    cout << "\n========================================" << endl;
    cout << "Visualization Complete / اكتمل التصور" << endl;
    cout << "========================================" << endl;
    
    return 0;
}

