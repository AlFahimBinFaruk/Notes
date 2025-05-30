* [Two sum](https://leetcode.com/problems/two-sum/)
```go
func twoSum(nums []int, target int) []int {
    var mpp=map[int]int{};
    var n=len(nums);
    var ans=[]int{};
    for i:=0;i<n;i++{
        var nd=target-nums[i];
        var _,ok=mpp[nd];
        if(ok){
            ans=append(ans,i,mpp[nd]);
            break;
        }
        mpp[nums[i]]=i;
    }

    return ans;

}
```