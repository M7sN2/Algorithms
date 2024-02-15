# Algorithms Course - Assignments & Projects

This project contains assignments and projects for Algorithms course as typically required by instructors in most colleges and institutes.

---

## Project Structure

```
algorithms/
├── assignments/
│   ├── sorting/
│   ├── search/
│   ├── recursion/
│   ├── graphs/
│   ├── hashing/
│   └── dynamic_programming/
│
├── projects/
│   ├── sorting_comparison/
│   ├── pathfinding/
│   └── graph_visualizer/
│
└── README.md
```

---

## Assignments

### 1. Sorting Algorithms
- **Bubble Sort**
- **Merge Sort**
- **Quick Sort**

### 2. Search Algorithms
- **Binary Search**
- **Linear Search**

### 3. Recursion
- **Fibonacci Sequence**
- **Factorial**

### 4. Graphs
- **BFS (Breadth-First Search)**
- **DFS (Depth-First Search)**

### 5. Hashing
- **Hash Table Implementation**

### 6. Dynamic Programming
- **Fibonacci (Memoization)**
- **Knapsack Problem**

---

## Projects

### 1. Sorting Comparison Tool
- Compares different sorting algorithms by execution time
- Supports Bubble, Merge, Quick, Insertion, Selection Sort

### 2. Pathfinding Algorithms
- **Dijkstra's Algorithm**
- **A* Algorithm**

### 3. Graph Visualizer
- Text-based graph visualization
- BFS and DFS traversal visualization

---

## Time Complexity Reference

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity |
|-----------|-----------|--------------|------------|------------------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| BFS | O(V+E) | O(V+E) | O(V+E) | O(V) |
| DFS | O(V+E) | O(V+E) | O(V+E) | O(V) |
| Hash Table (Average) | O(1) | O(1) | O(n) | O(n) |
| Hash Table (Worst) | O(n) | O(n) | O(n) | O(n) |
| Fibonacci (DP) | O(n) | O(n) | O(n) | O(n) |
| Knapsack (DP) | O(n*W) | O(n*W) | O(n*W) | O(n*W) |

---

## How to Use

### Requirements
- **C++ Compiler** (g++, clang++, or MSVC)

### Compilation & Execution

#### For Assignments:
```bash
g++ -o bubble_sort assignments/sorting/bubble_sort.cpp
./bubble_sort
```

#### For Projects:
```bash
cd projects/sorting_comparison
g++ -o sorting_comparison main.cpp -std=c++11
./sorting_comparison
```

---

## Notes

- All code is written in **C++**
- Code includes comments for clarity
- This project is for educational purposes only

---

## License

This project is for educational purposes only.
