* [Longest palindromic substring](https://leetcode.com/problems/longest-palindromic-substring/)
```go
var ans,a,b=0,0,0

var dp=make([][]int,1002)

func dfs(i int,j int,s string) int{
    if i>=j{
        return 1
    }
    if dp[i][j]!=-1{
        return dp[i][j]
    }

    f:=0
    if s[i]==s[j] && dfs(i+1,j-1,s)==1{
        f=1
        if (j-i)+1>ans{
            ans=(j-i)+1
            a=i
            b=j
        }
    }
    dfs(i+1,j,s)
    dfs(i,j-1,s)
    dp[i][j]=f
    return dp[i][j]
}

func longestPalindrome(s string) string {
    ans,a,b=0,0,0
    for i:=0;i<1002;i++{
		dp[i]=make([]int,1002)
		for j:=0;j<1002;j++{
			dp[i][j]=-1
		}
	}
    n:=len(s)
    dfs(0,n-1,s)
    res:=""
    for i:=a;i<=b;i++{
        res+=string(s[i])
    }
    return res
}
```