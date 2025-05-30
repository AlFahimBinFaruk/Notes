* [Number of Islands](https://leetcode.com/problems/number-of-islands/)
```go
import "container/list"

type Pair struct{
    a int;
    b int;
}

func bfs(i int,j int,n int,m int,grid [][]byte,vis map[Pair]struct{}){
    q:=list.New();
    q.PushBack(Pair{a:i,b:j});

    for q.Len()>0{
        elm:=q.Front();
        q.Remove(elm);
        temp:=elm.Value.(Pair);
        var _,ok=vis[temp];
        if ok{
            continue;
        }
        vis[temp]=struct{}{};
        a,b:=temp.a,temp.b;
        if a-1>=0 && grid[a-1][b]=='1'{
            q.PushBack(Pair{a:a-1,b:b});
        }
        if a+1<n && grid[a+1][b]=='1'{
            q.PushBack(Pair{a:a+1,b:b});
        }
        if b-1>=0 && grid[a][b-1]=='1'{
            q.PushBack(Pair{a:a,b:b-1});
        }
        if b+1<m && grid[a][b+1]=='1'{
            q.PushBack(Pair{a:a,b:b+1});
        }
    }
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
                bfs(i,j,n,m,grid,vis);
            }
        }
    }
    return cnt;
}
```