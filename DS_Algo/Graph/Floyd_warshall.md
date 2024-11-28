## Floye warshall algo.
* [Problem](https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1)
* [Striver](https://www.youtube.com/watch?v=YbY8cVwWAvw)
* We are exploring paths to "A->B" via all possible "I" which is making sure that at last we have the Shortest path.
* Works for both DG,UG and Negatives weights.
* Time: O(V^3)
* Space: O(V^2)
```cpp
class Solution {
  public:

    void shortestDistance(vector<vector<int>>& mat) {
        
        int n=mat.size();
        
        for(int i=0;i<n;i++){
            for(int a=0;a<n;a++){
                for(int b=0;b<n;b++){
                    if(mat[a][i]!=-1 and mat[i][b]!=-1 and (mat[a][i]+mat[i][b]<mat[a][b] or mat[a][b]==-1)){
                        mat[a][b]=mat[a][i]+mat[i][b];
                    }
                }
            }
        }
    }
};
```
