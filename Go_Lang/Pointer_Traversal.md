* [Reverse LL](https://leetcode.com/problems/reverse-linked-list/)
```go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    var prev,nh *ListNode=nil,nil;

    for head!=nil{
        var temp *ListNode=head.Next;
        nh=head;
        nh.Next=prev;
        prev=nh;
        head=temp;
    }

    return prev;
}
```