### Dijkstra
* [Problem Link](https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1)
* Shortest path is DAG approach won't work because it dosen't make sure that we are processing all the possible parents
of x before processing x like this test case:
```text
4 4
0 1 10
0 2 1
2 1 1
1 3 1
0
```

```cpp
// Time O(V+ElogV), Worst O(E+ElogV)
// Space O(E+V)
class Solution {
  public:
    
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n=adj.size();
       

        vector<int>ans(n,1e9);

        // set<pair<int,int>>St;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        pq.push({0,src});

        // set<int>vis;

        while(pq.size()>0){
            pair<int,int>cur=pq.top();
            pq.pop();

            // if(vis.find(cur.second)!=vis.end()){
            //     continue;
            // }
            // vis.insert(cur.second);

            if(cur.first>=ans[cur.second]){
                continue;
            }
            ans[cur.second]=cur.first;

            for(pair<int,int>c:adj[cur.second]){
                int cost=cur.first+c.second;
                if(cost<ans[c.first]){
                    pq.push({cost,c.first});
                }
            }
        }

        return ans;

    }
};
```
