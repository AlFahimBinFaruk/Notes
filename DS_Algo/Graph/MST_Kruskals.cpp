// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/

/*

Union by size: This is as same as the Union by rank method except this method uses the size to compare the components while connecting. 
That is why we need a ‘size’ array of size N(no. of nodes) instead of a rank array. 
The size array will be storing the size for each particular node i.e. size[i] will be the size of the component starting from node i.
Typically, the size of a node refers to the number of nodes that are connected to it.

****************************
Rank:
The rank of a node generally refers to the distance (the number of nodes including the leaf node) between the furthest leaf node and the current node. 
Basically rank includes all the nodes beneath the current node.

****************************
What is path compression?
Basically, connecting each node in a particular path to its ultimate parent refers to path compression. 


*/
class DSU{
    int *parent;
    int *rank;
    int *size;

    public:
        DSU(int n){
            parent=new int[n];
            rank=new int[n];

            for(int i=0;i<n;i++){
                parent[i]=-1;
                rank[i]=1;
                size[i]=1;
            }
        }


        int find(int i){
            if(parent[i]==-1){
                return i;
            }
            //when we are connection two nodes means we are connection their parents.
            return parent[i]=find(parent[i]);
        }

        bool uniteByRank(int x,int y){
            int s1=find(x);
            int s2=find(y);

            if(s1!=s2){

                if(rank[s1]>rank[s2]){
                    parent[s2]=s1;
                }else if(rank[s1]<rank[s2]){
                    parent[s1]=s2;
                }else{
                    parent[s2]=s1;
                    rank[s1]++;
                }

                return true;

            }
            return false;


        }



        bool uniteBySize(int x,int y){
            int s1=find(x);
            int s2=find(y);

            if(s1!=s2){

                if(size[s1]>size[s2]){
                    parent[s2]=s1;
                    size[s1]+=size[s2];
                }else{
                    parent[s1]=s2;
                    size[s2]+=size[s1];
                }

                return true;

            }
            return false;


        }

};

class Solution
{
	public:
	// Time = O(E*logE)+O(E*logV) = O(E*logE) or O(E*logV)
	// Space = O(E) + O(N)
	int spanningTree(int V, vector<vector<int>> adj[]){
	
	        DSU dsu(V);
	
	        vector<vector<int>>arr;
	
	        for(int i=0;i<V;i++){
	            for(auto brr:adj[i]){
	                vector<int>temp;
	                temp.push_back(brr[1]);
	                temp.push_back(i);
	                temp.push_back(brr[0]);
	                arr.push_back(temp);
	            }
	        }
	        sort(arr.begin(),arr.end());
	        
	        int cnt=0;
	
	        // conection more than v-1 edge will ultimately result in cycle so no need to check separetely.
	        for(int i=0;i<arr.size();i++){
	            int w=arr[i][0],a=arr[i][1],b=arr[i][2];
	
	            if(dsu.find(a)!=dsu.find(b)){
	                dsu.unite(a,b);
	                cnt+=w;
	            }
	            
	        }
	
	        return cnt;
	};
    
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
