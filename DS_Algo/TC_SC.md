## Time and Space Complexity of DS & Algos

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

### **Linked List Singly,Doubly Operations**

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

### **Sorting Algorithms**

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

---

### **Searching Algorithms**

| Algorithm                 | Time Complexity (Best) | Time Complexity (Average) | Time Complexity (Worst) | Space Complexity |
|---------------------------|------------------------|---------------------------|--------------------------|------------------|
| **Linear Search**         | O(1)                  | O(n)                      | O(n)                     | O(1)             |
| **Binary Search**         | O(1)                  | O(log n)                  | O(log n)                 | O(1)             |
| **Depth-First Search**    | O(V+E)                | O(V+E)                    | O(V+E)                   | O(V)             |
| **Breadth-First Search**  | O(V+E)                | O(V+E)                    | O(V+E)                   | O(V)             |

---

### **Graph Algorithms**

| Algorithm                          | Time Complexity     | Space Complexity | Description                                               |
|------------------------------------|---------------------|------------------|-----------------------------------------------------------|
| **Dijkstra's Algorithm**           | O((V + E) log V)   | O(V + E)        | Shortest path in weighted graphs                          |
| **Floyd-Warshall Algorithm**       | O(V^3)             | O(V^2)          | All-pairs shortest paths                                  |
| **Bellman-Ford Algorithm**         | O(V \* E)          | O(V)            | Shortest path in graphs with negative weights             |
| **Kruskal's Algorithm**            | O(E log E)         | O(V + E)        | Minimum spanning tree                                     |
| **Prim's Algorithm**               | O((V + E) log V)   | O(V + E)        | Minimum spanning tree                                     |
| **Topological Sort (Kahn's)**      | O(V + E)           | O(V)            | Order nodes in Directed Acyclic Graphs (DAGs)             |
| **Tarjan's Algorithm**             | O(V + E)           | O(V)            | Strongly connected components                             |

---

### **Time Complexity Set**

| Operation                    | Time Complexity | 
|------------------------------|-----------------|
| **Insertion** (`insert`)     | \( O(\log n) \) |
| **Deletion** (`erase`)       | \( O(\log n) \) |
| **Search** (`find`)          | \( O(\log n) \) |
| **Count** (`count`)          | \( O(\log n) \) |
| **Minimum Element** (`begin`) | \( O(1) \)      |
| **Maximum Element** (`rbegin`) | \( O(1) \)    | 
| **Lower Bound** (`lower_bound`) | \( O(\log n) \) |
| **Upper Bound** (`upper_bound`) | \( O(\log n) \) |

### **Data Structures Summary**

| Data Structure        | Access    | Search    | Insertion | Deletion | Space   |
|-----------------------|-----------|-----------|-----------|----------|---------|
| **Array**             | O(1)      | O(n)      | O(n)      | O(n)     | O(n)    |
| **Stack**             | O(n)      | O(n)      | O(1)      | O(1)     | O(n)    |
| **Queue**             | O(n)      | O(n)      | O(1)      | O(1)     | O(n)    |
| **Linked List**       | O(n)      | O(n)      | O(1)      | O(1)     | O(n)    |
| **Hash Table**        | -         | O(1)      | O(1)      | O(1)     | O(n)    |
| **Binary Search Tree**| O(log n)  | O(log n)  | O(log n)  | O(log n) | O(n)    |
| **Heap**              | O(n)      | O(n)      | O(log n)  | O(log n) | O(n)    |
| **Graph**             | -         | O(V + E)  | O(1)      | O(1)     | O(V + E)|


