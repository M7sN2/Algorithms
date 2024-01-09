/*
 * A* Pathfinding Algorithm
 * خوارزمية البحث عن المسار A*
 * 
 * A* is an informed search algorithm that finds the shortest path
 * from a start node to a goal node in a weighted graph.
 * 
 * A* هي خوارزمية بحث مطلعة تجد أقصر مسار
 * من عقدة البداية إلى عقدة الهدف في رسم بياني موزون.
 * 
 * It uses: f(n) = g(n) + h(n)
 * where g(n) = cost from start to n
 *       h(n) = heuristic estimate from n to goal
 * 
 * Time Complexity: O(b^d) where b = branching factor, d = depth
 * Space Complexity: O(b^d)
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;

struct Node {
    int x, y;  // Coordinates
    int g;     // Cost from start
    int h;     // Heuristic (estimated cost to goal)
    int f;     // Total cost (g + h)
    pair<int, int> parent;  // Parent coordinates
    
    Node(int x, int y) : x(x), y(y), g(0), h(0), f(0), parent(-1, -1) {}
    
    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

class AStar {
private:
    int rows, cols;
    vector<vector<int>> grid;  // 0 = walkable, 1 = obstacle
    vector<vector<bool>> closedSet;
    
    // Heuristic function (Manhattan distance)
    // دالة الاستدلال (مسافة مانهاتن)
    int heuristic(int x1, int y1, int x2, int y2) {
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    // Check if coordinates are valid
    // التحقق من صحة الإحداثيات
    bool isValid(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0;
    }
    
public:
    AStar(int rows, int cols) : rows(rows), cols(cols) {
        grid.resize(rows, vector<int>(cols, 0));
        closedSet.resize(rows, vector<bool>(cols, false));
    }
    
    // Set obstacle
    // تعيين عائق
    void setObstacle(int x, int y) {
        if (isValid(x, y)) {
            grid[x][y] = 1;
        }
    }
    
    // Find path using A* algorithm
    // إيجاد المسار باستخدام خوارزمية A*
    vector<pair<int, int>> findPath(int startX, int startY, int goalX, int goalY) {
        priority_queue<Node, vector<Node>, greater<Node>> openSet;
        
        // Parent map to reconstruct path
        // خريطة الوالدين لإعادة بناء المسار
        vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));
        
        Node start(startX, startY);
        start.h = heuristic(startX, startY, goalX, goalY);
        start.f = start.g + start.h;
        
        openSet.push(start);
        
        vector<vector<int>> gScore(rows, vector<int>(cols, INT_MAX));
        gScore[startX][startY] = 0;
        parent[startX][startY] = {startX, startY};  // Start is its own parent
        
        // Directions: up, down, left, right
        // الاتجاهات: أعلى، أسفل، يسار، يمين
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while (!openSet.empty()) {
            Node current = openSet.top();
            openSet.pop();
            
            if (closedSet[current.x][current.y]) {
                continue;
            }
            
            closedSet[current.x][current.y] = true;
            
            // Check if goal reached
            // التحقق من الوصول للهدف
            if (current.x == goalX && current.y == goalY) {
                // Reconstruct path
                // إعادة بناء المسار
                vector<pair<int, int>> path;
                pair<int, int> curr = {goalX, goalY};
                
                // Build path backwards
                // بناء المسار للخلف
                while (curr.first != -1 && curr.second != -1) {
                    path.push_back(curr);
                    if (curr == parent[curr.first][curr.second]) {
                        break;  // Reached start
                    }
                    curr = parent[curr.first][curr.second];
                }
                
                reverse(path.begin(), path.end());
                return path;
            }
            
            // Explore neighbors
            // استكشاف الجيران
            for (int i = 0; i < 4; i++) {
                int newX = current.x + dx[i];
                int newY = current.y + dy[i];
                
                if (!isValid(newX, newY) || closedSet[newX][newY]) {
                    continue;
                }
                
                int tentativeG = gScore[current.x][current.y] + 1;
                
                if (tentativeG < gScore[newX][newY]) {
                    Node neighbor(newX, newY);
                    neighbor.g = tentativeG;
                    neighbor.h = heuristic(newX, newY, goalX, goalY);
                    neighbor.f = neighbor.g + neighbor.h;
                    
                    gScore[newX][newY] = tentativeG;
                    parent[newX][newY] = {current.x, current.y};
                    openSet.push(neighbor);
                }
            }
        }
        
        return {};  // No path found
    }
    
    // Print grid with path
    // طباعة الشبكة مع المسار
    void printGridWithPath(const vector<pair<int, int>>& path, 
                          int startX, int startY, int goalX, int goalY) {
        vector<vector<char>> display(rows, vector<char>(cols, '.'));
        
        // Mark obstacles
        // تعليم العوائق
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    display[i][j] = '#';
                }
            }
        }
        
        // Mark path
        // تعليم المسار
        for (const auto& p : path) {
            if (p.first == startX && p.second == startY) {
                display[p.first][p.second] = 'S';  // Start
            } else if (p.first == goalX && p.second == goalY) {
                display[p.first][p.second] = 'G';  // Goal
            } else {
                display[p.first][p.second] = '*';  // Path
            }
        }
        
        cout << "\nGrid with Path / الشبكة مع المسار:" << endl;
        cout << "S = Start / البداية, G = Goal / الهدف, * = Path / المسار, # = Obstacle / عائق\n" << endl;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << display[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    cout << "A* Pathfinding Algorithm / خوارزمية البحث عن المسار A*" << endl;
    cout << "======================================================" << endl;
    
    // Create a 10x10 grid
    // إنشاء شبكة 10x10
    AStar astar(10, 10);
    
    // Add some obstacles
    // إضافة بعض العوائق
    for (int i = 2; i < 8; i++) {
        astar.setObstacle(i, 4);
    }
    for (int i = 1; i < 5; i++) {
        astar.setObstacle(5, i);
    }
    
    int startX = 0, startY = 0;
    int goalX = 9, goalY = 9;
    
    cout << "Finding path from (" << startX << ", " << startY 
         << ") to (" << goalX << ", " << goalY << ")..." << endl;
    
    vector<pair<int, int>> path = astar.findPath(startX, startY, goalX, goalY);
    
    if (!path.empty()) {
        cout << "\nPath found! / تم إيجاد المسار!" << endl;
        cout << "Path length / طول المسار: " << path.size() - 1 << " steps" << endl;
        cout << "\nPath coordinates / إحداثيات المسار:" << endl;
        for (const auto& p : path) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
        
        astar.printGridWithPath(path, startX, startY, goalX, goalY);
    } else {
        cout << "\nNo path found! / لم يتم إيجاد مسار!" << endl;
    }
    
    return 0;
}

