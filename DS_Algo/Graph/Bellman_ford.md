## Bellman Ford algo.
* [Striver](https://www.youtube.com/watch?v=0vVofAhAYjc)
* [Problem](https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1)
* Bellman ford works to find the sortest path from src node to other node when the weights of the Nodes can be Negative.
* A node can have at max V-1 other connectinons so V-1 iterations is enough to get the overall optimal path to reach the node as by this time we have explored every possible combinations so if in Vth iteration we still find any Nodes whch values can still be minimized that means there is an Negative cyclce.
* Time:O(V*E)
* Space:O(V)
```cpp
 class Solution {
  public:
    
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        vector<int>ans(V,1e8);
        ans[src]=0;
        for(int i=1;i<=V;i++){
            for(vector<int>temp:edges){
                int u=temp[0],v=temp[1],w=temp[2];
                if(ans[u]!=1e8 and ans[v]>ans[u]+w){
                    if(i==V){
                        return {-1};
                    }
                    ans[v]=ans[u]+w;

                }
            }
        }

        return ans;
    }
};




int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int N, m;
        cin >> N >> m;

        vector<vector<int> > edges;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(N, edges, src);

        
    }
    return 0;
}

```
