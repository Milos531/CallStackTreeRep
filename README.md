# CallStackTreeRep

Builds a call tree from program call stacks, converts it to a graph, traverses it with BFS, and detects potential recursion (cycles). Implemented in modern C++ with custom Stack/Queue templates.

## Features
- Parse call stacks from a text file (one call stack per line)
- Construct a rooted tree of function calls
- Preorder traversal printing
- Convert the tree into an adjacency-matrix graph
- BFS traversal of the graph
- Simple cycle detection to flag potential recursion
- Add or remove stacks interactively via a CLI menu

## Project structure
- `main.cpp` – CLI menu (Serbian UI) and program entry
- `Stablo.h/.cpp` – Tree and graph logic (nodes, adjacency matrix, traversals, cycle check)
- `Stack.h` – Generic LIFO stack (template)
- `Queue.h` – Generic FIFO queue (template)
- `stekovi.txt` – Sample input of call stacks

Data structures and algorithms
- Tree nodes store: key (function name), parent, and vector of children
- Conversion to graph via adjacency matrix (up to 100 nodes)
- Traversals: preorder (stack-based), BFS (queue-based)

## Input format
Each line represents a call stack from root to leaf, with function names separated by spaces. Example (`stekovi.txt`):
```
main a c d
main a d
main b c c d
main b c d
```
