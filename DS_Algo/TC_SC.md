## Time and Space complexity of DS & Algos.

### **Array Operations**

| Operation            | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|----------------------|---------------------------|--------------------------|-------------------|
| Access (by index)    | \(O(1)\)                  | \(O(1)\)                 | \(O(n)\)         |
| Search               | \(O(n)\)                  | \(O(n)\)                 | \(O(1)\)         |
| Insertion (end)      | \(O(1)\)                  | \(O(n)\)                 | \(O(n)\)         |
| Insertion (middle)   | \(O(n)\)                  | \(O(n)\)                 | \(O(n)\)         |
| Deletion (end)       | \(O(1)\)                  | \(O(1)\)                 | \(O(n)\)         |
| Deletion (middle)    | \(O(n)\)                  | \(O(n)\)                 | \(O(n)\)         |

---

### **Linked List Operations**

| Operation            | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|----------------------|---------------------------|--------------------------|-------------------|
| Access (by index)    | \(O(n)\)                  | \(O(n)\)                 | \(O(n)\)         |
| Search               | \(O(n)\)                  | \(O(n)\)                 | \(O(n)\)         |
| Insertion (at head)  | \(O(1)\)                  | \(O(1)\)                 | \(O(n)\)         |
| Insertion (end)      | \(O(1)\) with tail ptr    | \(O(n)\)                 | \(O(n)\)         |
| Deletion (at head)   | \(O(1)\)                  | \(O(1)\)                 | \(O(n)\)         |
| Deletion (end)       | \(O(n)\)                  | \(O(n)\)                 | \(O(n)\)         |

---

### **Stack Operations**

| Operation            | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|----------------------|---------------------------|--------------------------|-------------------|
| Push                 | \(O(1)\)                  | \(O(1)\)                 | \(O(n)\)         |
| Pop                  | \(O(1)\)                  | \(O(1)\)                 | \(O(n)\)         |
| Top                  | \(O(1)\)                  | \(O(1)\)                 | \(O(n)\)         |
| Search               | \(O(n)\)                  | \(O(n)\)                 | \(O(n)\)         |

---

### **Queue Operations**

| Operation            | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|----------------------|---------------------------|--------------------------|-------------------|
| Enqueue              | \(O(1)\)                  | \(O(1)\)                 | \(O(n)\)         |
| Dequeue              | \(O(1)\)                  | \(O(1)\)                 | \(O(n)\)         |
| Front/Peek           | \(O(1)\)                  | \(O(1)\)                 | \(O(n)\)         |
| Search               | \(O(n)\)                  | \(O(n)\)                 | \(O(n)\)         |

---

### **Hash Table (Unordered Map)**

| Operation            | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|----------------------|---------------------------|--------------------------|-------------------|
| Insertion            | \(O(1)\)                  | \(O(n)\)                 | \(O(n)\)         |
| Deletion             | \(O(1)\)                  | \(O(n)\)                 | \(O(n)\)         |
| Search               | \(O(1)\)                  | \(O(n)\)                 | \(O(n)\)         |

---

### **Binary Search Tree (BST)**

| Operation            | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|----------------------|---------------------------|--------------------------|-------------------|
| Insertion            | \(O(\log n)\)             | \(O(n)\)                 | \(O(n)\)         |
| Deletion             | \(O(\log n)\)             | \(O(n)\)                 | \(O(n)\)         |
| Search               | \(O(\log n)\)             | \(O(n)\)                 | \(O(n)\)         |

---

### **Binary Heap (Min/Max Heap)**

| Operation            | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|----------------------|---------------------------|--------------------------|-------------------|
| Insert               | \(O(\log n)\)             | \(O(\log n)\)            | \(O(n)\)         |
| Delete (min/max)     | \(O(\log n)\)             | \(O(\log n)\)            | \(O(n)\)         |
| Peek (min/max)       | \(O(1)\)                  | \(O(1)\)                 | \(O(n)\)         |

---

### **Graph Algorithms**

| Algorithm                      | Time Complexity                       | Space Complexity   |
|--------------------------------|---------------------------------------|---------------------|
| BFS                            | \(O(V + E)\)                          | \(O(V)\)           |
| DFS                            | \(O(V + E)\)                          | \(O(V)\)           |
| Dijkstra’s Algorithm           | \(O((V + E) \log V)\)                 | \(O(V + E)\)       |
| Bellman-Ford Algorithm         | \(O(V \cdot E)\)                      | \(O(V)\)           |
| Floyd-Warshall Algorithm       | \(O(V^3)\)                            | \(O(V^2)\)         |
| Prim’s Algorithm (MST)         | \(O((V + E) \log V)\)                 | \(O(V + E)\)       |
| Kruskal’s Algorithm (MST)      | \(O(E \log E)\)                       | \(O(V + E)\)       |

---

### Data Structures

| Data Structure        | Access    | Search    | Insertion | Deletion | Space   |
|-----------------------|-----------|-----------|-----------|----------|---------|
| **Array**             | O(1)      | O(n)      | O(n)      | O(n)     | O(n)    |
| **Stack**             | O(n)      | O(n)      | O(1)      | O(1)     | O(n)    |
| **Queue**             | O(n)      | O(n)      | O(1)      | O(1)     | O(n)    |
| **Singly Linked List**| O(n)      | O(n)      | O(1)      | O(1)     | O(n)    |
| **Doubly Linked List**| O(n)      | O(n)      | O(1)      | O(1)     | O(n)    |
| **Hash Table**        | -         | O(1)      | O(1)      | O(1)     | O(n)    |
| **Binary Search Tree**| O(log n)  | O(log n)  | O(log n)  | O(log n) | O(n)    |
| **AVL Tree**          | O(log n)  | O(log n)  | O(log n)  | O(log n) | O(n)    |
| **Red-Black Tree**    | O(log n)  | O(log n)  | O(log n)  | O(log n) | O(n)    |
| **Heap**              | O(1)      | O(n)      | O(log n)  | O(log n) | O(n)    |
| **Trie**              | O(m)      | O(m)      | O(m)      | O(m)     | O(m \* n) |
| **Graph (Adj. List)** | O(V+E)    | O(V+E)    | O(1)      | O(E)     | O(V+E)  |
| **Graph (Adj. Matrix)** | O(V)   | O(1)      | O(1)      | O(V)     | O(V^2)  |

### Sorting Algorithms

| Algorithm                | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity | Stable |
|--------------------------|------------------------|---------------------------|--------------------------|------------------|--------|
| **Bubble Sort**          | O(n)                  | O(n^2)                    | O(n^2)                   | O(1)             | Yes    |
| **Selection Sort**       | O(n^2)                | O(n^2)                    | O(n^2)                   | O(1)             | No     |
| **Insertion Sort**       | O(n)                  | O(n^2)                    | O(n^2)                   | O(1)             | Yes    |
| **Merge Sort**           | O(n log n)            | O(n log n)                | O(n log n)               | O(n)             | Yes    |
| **Quick Sort**           | O(n log n)            | O(n log n)                | O(n^2)                   | O(log n)         | No     |
| **Heap Sort**            | O(n log n)            | O(n log n)                | O(n log n)               | O(1)             | No     |
| **Counting Sort**        | O(n + k)              | O(n + k)                  | O(n + k)                 | O(k)             | Yes    |
| **Radix Sort**           | O(nk)                 | O(nk)                     | O(nk)                    | O(n + k)         | Yes    |
| **Bucket Sort**          | O(n + k)              | O(n + k)                  | O(n^2)                   | O(n)             | Yes    |

### Searching Algorithms

| Algorithm                 | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|---------------------------|------------------------|---------------------------|--------------------------|------------------|
| **Linear Search**         | O(1)                  | O(n)                      | O(n)                     | O(1)             |
| **Binary Search**         | O(1)                  | O(log n)                  | O(log n)                 | O(1)             |
| **Depth-First Search**    | O(V+E)                | O(V+E)                    | O(V+E)                   | O(V)             |
| **Breadth-First Search**  | O(V+E)                | O(V+E)                    | O(V+E)                   | O(V)             |


### Graph Algorithms

| Algorithm                          | Time Complexity     | Space Complexity | Description                                               |
|------------------------------------|---------------------|------------------|-----------------------------------------------------------|
| **Dijkstra's Algorithm**           | O((V + E) log V)   | O(V + E)        | Shortest path in weighted graphs                          |
| **Floyd-Warshall Algorithm**       | O(V^3)             | O(V^2)          | All-pairs shortest paths                                  |
| **Bellman-Ford Algorithm**         | O(V \* E)          | O(V)            | Shortest path in graphs with negative weights             |
| **Kruskal's Algorithm**            | O(E log E)         | O(V + E)        | Minimum spanning tree                                     |
| **Prim's Algorithm**               | O((V + E) log V)   | O(V + E)        | Minimum spanning tree                                     |
| **Topological Sort (Kahn's)**      | O(V + E)           | O(V)            | Order nodes in Directed Acyclic Graphs (DAGs)             |
| **Tarjan's Algorithm**             | O(V + E)           | O(V)            | Strongly connected components                             |

### Advanced Data Structures

| Data Structure                | Insertion | Deletion | Search | Space |
|-------------------------------|-----------|----------|--------|-------|
| **Segment Tree**              | O(log n)  | O(log n) | O(log n) | O(n) |
| **Fenwick Tree (BIT)**        | O(log n)  | O(log n) | O(log n) | O(n) |
| **Trie**                      | O(m)      | O(m)     | O(m)   | O(m \* n) |
| **Disjoint Set (Union-Find)** | O(α(n))   | O(α(n))  | O(α(n)) | O(n) |

---

### Key

- **n** = number of elements in the data structure or list
- **V** = number of vertices in a graph
- **E** = number of edges in a graph
- **m** = length of the longest key (for Trie operations)
- **W** = Knapsack capacity (for dynamic programming)
- **α(n)** = inverse Ackermann function, very close to O(1)
