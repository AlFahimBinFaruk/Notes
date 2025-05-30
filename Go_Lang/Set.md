* [Divide arr into equal pairs](https://leetcode.com/problems/divide-array-into-equal-pairs/)
```go
func divideArray(nums []int) bool {
    var st=make(map[int]struct{});
    var n=len(nums);

    for i:=0;i<n;i++{
        var _,ok=st[nums[i]];
        if ok{
            delete(st,nums[i]);
        }else{
            st[nums[i]]=struct{}{};
        }
    }

    return len(st)==0;
}
```