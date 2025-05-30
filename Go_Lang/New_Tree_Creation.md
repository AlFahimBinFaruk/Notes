* [Invert Tree](https://leetcode.com/problems/invert-binary-tree/)
```go
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func invertTree(root *TreeNode) *TreeNode {
    if(root==nil){
        return nil;
    }
    var nw *TreeNode=&TreeNode{Val:root.Val};
    nw.Left=invertTree(root.Right);
    nw.Right=invertTree(root.Left);
    return nw;
}
```