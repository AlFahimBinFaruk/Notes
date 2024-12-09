## Common Time Complexities and Their Names

### **1. Constant Time Complexity - `O(1)`**
- **Name:** Constant Time
- **Description:** The algorithm takes the same amount of time regardless of the input size.
- **Example:** Accessing an element in an array by index.

---

### **2. Logarithmic Time Complexity - `O(log N)`**
- **Name:** Logarithmic Time
- **Description:** The algorithm's time grows logarithmically with the input size.
- **Example:** Binary search in a sorted array.

---

### **3. Linear Time Complexity - `O(N)`**
- **Name:** Linear Time
- **Description:** The time taken grows linearly with the size of the input.
- **Example:** Traversing an array.

---

### **4. Linearithmic Time Complexity - `O(N log N)`**
- **Name:** Linearithmic Time
- **Description:** Combines linear and logarithmic growth; common in efficient sorting algorithms.
- **Example:** Merge sort, quicksort (average case).

---

### **5. Quadratic Time Complexity - `O(N^2)`**
- **Name:** Quadratic Time
- **Description:** The time taken grows with the square of the input size.
- **Example:** Nested loops, such as comparing all pairs of elements.

---

### **6. Cubic Time Complexity - `O(N^3)`**
- **Name:** Cubic Time
- **Description:** The time grows with the cube of the input size.
- **Example:** Triple nested loops, such as matrix multiplication.

---

### **7. Polynomial Time Complexity - `O(N^k)`**
- **Name:** Polynomial Time
- **Description:** A generalization of quadratic and cubic times; `k` is any constant.
- **Example:** Certain graph algorithms, like finding all paths of a fixed length `k`.

---

### **8. Exponential Time Complexity - `O(2^N)`, `O(3^N)`, etc.**
- **Name:** Exponential Time
- **Description:** The time grows exponentially with the input size.
- **Example:** Solving the traveling salesman problem (TSP) using brute force.

---

### **9. Factorial Time Complexity - `O(N!)`**
- **Name:** Factorial Time
- **Description:** The time grows with the factorial of the input size.
- **Example:** Brute-force solutions to the traveling salesman problem.

---

### **10. Square Root Time Complexity - `O(√N)`**
- **Name:** Square Root Time
- **Description:** The time grows with the square root of the input size.
- **Example:** Prime factorization or loop iterations up to `√N`.

---

### **11. Log-Logarithmic Time Complexity - `O(log(log N))`**
- **Name:** Double Logarithmic Time
- **Description:** Extremely fast-growing time complexity; rare in practice.
- **Example:** Certain advanced computational techniques.

---

### **12. Sublinear Time Complexity - `O(N^c)` where `0 < c < 1`**
- **Name:** Sublinear Time
- **Description:** Less than linear growth; often found in approximate algorithms.
- **Example:** Binary search or sampling-based techniques.

---

### **13. Superlinear Time Complexity - `O(N log N)`, `O(N^(1+c))`**
- **Name:** Superlinear Time
- **Description:** Slightly faster than quadratic but slower than linearithmic.
- **Example:** Algorithms slightly faster than naive approaches.

---

### **14. Constant-Amortized Time Complexity**
- **Name:** Amortized Constant Time
- **Description:** The average time for a sequence of operations is constant.
- **Example:** Dynamic array resizing in `push` operations.

---

### **15. Subquadratic Time Complexity**
- **Name:** Subquadratic Time
- **Description:** Faster than quadratic (`O(N^2)`) but slower than linearithmic (`O(N log N)`).
- **Example:** Shell sort (worst-case).

---

### **16. Quasilinear Time Complexity**
- **Name:** Quasilinear Time
- **Description:** Similar to `O(N log N)` but specific to sorting and divide-and-conquer algorithms.
- **Example:** Heap sort.

---


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


