### Bucket Sort
* It is mainly used for floating point numbers and where difference between numbers is small.
* [GFG](https://www.geeksforgeeks.org/bucket-sort-2/)
* Time: O(N+K)
* Space: O(N+K)
```cpp
// This can be any sorting algo.
void insertionSort(vector<float>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to sort arr[] of size n using bucket sort
void bucketSort(float arr[], int n) {
    // 1) Create n empty buckets
    vector<float> b[n];

    // 2) Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    // 3) Sort individual buckets using insertion sort
    for (int i = 0; i < n; i++) {
        insertionSort(b[i]);
    }

    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}
```

```cpp
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // Find the minimum and maximum values in the array
    int minValue = *min_element(arr.begin(), arr.end());
    int maxValue = *max_element(arr.begin(), arr.end());

    // Calculate the range of values
    int range = maxValue - minValue + 1;

    // Create `range` number of buckets
    vector<vector<int>> buckets(range);

    // Map array elements to buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] - minValue; // Adjust index for negative numbers
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Concatenate all buckets into the original array
    int index = 0;
    for (int i = 0; i < range; i++) {
        for (int val : buckets[i]) {
            arr[index++] = val;
        }
    }
}
```
