* [Number of Islands](https://leetcode.com/problems/number-of-islands/)
```go
type Pair struct{
    a int;
    b int;
}

func dfs(i int,j int,n int,m int,grid [][]byte,vis map[Pair]struct{}){
    temp:=Pair{a:i,b:j};
    var _,ok=vis[temp];
    if i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1' || ok{
        return
    }
    vis[temp]=struct{}{};
    dfs(i-1,j,n,m,grid,vis);
    dfs(i+1,j,n,m,grid,vis);
    dfs(i,j-1,n,m,grid,vis);
    dfs(i,j+1,n,m,grid,vis);
}

func numIslands(grid [][]byte) int {
    n:=len(grid)
    m:=len(grid[0])
    vis:=make(map[Pair]struct{});
    var cnt=0;
    for i:=0;i<n;i++{
        for j:=0;j<m;j++{
            temp:=Pair{a:i,b:j};
            var _,ok=vis[temp];
            if !ok && grid[i][j]=='1'{
                cnt++;
                dfs(i,j,n,m,grid,vis);
            }
        }
    }
    return cnt;
}
```