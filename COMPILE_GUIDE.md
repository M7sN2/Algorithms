# Quick Compile Guide
# دليل الترجمة السريع

## Windows / ويندوز

### Using MinGW / استخدام MinGW

```bash
# Navigate to assignment folder
cd assignments/sorting

# Compile
g++ -o bubble_sort bubble_sort.cpp

# Run
./bubble_sort.exe
```

### Using Visual Studio / استخدام Visual Studio

1. Open Developer Command Prompt
2. Navigate to project folder
3. Compile: `cl /EHsc filename.cpp`
4. Run: `filename.exe`

## Linux / لينكس

```bash
# Navigate to assignment folder
cd assignments/sorting

# Compile
g++ -o bubble_sort bubble_sort.cpp

# Run
./bubble_sort
```

## macOS / ماك

```bash
# Install Xcode Command Line Tools if needed
xcode-select --install

# Compile and run (same as Linux)
g++ -o bubble_sort bubble_sort.cpp
./bubble_sort
```

## Projects / المشاريع

### Sorting Comparison
```bash
cd projects/sorting_comparison
g++ -o sorting_comparison main.cpp -std=c++11
./sorting_comparison
```

### Pathfinding
```bash
cd projects/pathfinding
g++ -o dijkstra dijkstra.cpp
g++ -o astar astar.cpp -std=c++11
./dijkstra
./astar
```

### Graph Visualizer
```bash
cd projects/graph_visualizer
g++ -o graph_visualizer main.cpp -std=c++11
./graph_visualizer
```

## Tips / نصائح

- Use `-std=c++11` or higher for modern C++ features
- Use `-Wall` for warnings: `g++ -Wall -o program program.cpp`
- Use `-O2` for optimization: `g++ -O2 -o program program.cpp`

