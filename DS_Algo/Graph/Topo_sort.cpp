// Kahn's Algo.
class Solution {
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        
        int n=adj.size();
        
        vector<int>ind(n,0);
        
        for(int i=0;i<n;i++){
            for(int cur:adj[i]){
                ind[cur]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        
        while(q.size()>0){
            int cur=q.front();
            q.pop();
            ans.push_back(cur);
            
            for(int i:adj[cur]){
                ind[i]--;
                if(ind[i]==0){
                    q.push(i);
                }
            }
        }
        
        return ans;
        
    }
};


// DFS.
class Solution{
public:
    set<int>vis;
    vector<int>ans;

    void dfs(int cur,vector<int> adj[]){
      
        vis.insert(cur);
        for(int i:adj[cur]){
            if(vis.find(i)==vis.end()){
                dfs(i,adj);
            }
        }
        ans.push_back(cur);
    }

     vector<int> topoSort(int V, vector<int> adj[]){

         vis.clear();
         ans.clear();

         for(int i=0;i<V;i++){
             if(vis.find(i)==vis.end()){
                 dfs(i,adj);
             }
         }

         reverse(ans.begin(),ans.end());
         return ans;
     }
}
