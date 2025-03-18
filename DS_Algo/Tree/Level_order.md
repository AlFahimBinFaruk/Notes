* root->left->right
* T O(N) , S O(N)
## CPP
```cpp
void sol(TreeNode<int>* root,vector<int>&arr){
    if(root==NULL)return;

    queue<TreeNode<int> *>q;
    q.push(root);
    while(!q.empty()){
        root=q.front();
        q.pop();
        arr.push_back(root->data);
        if(root->left!=NULL){
            q.push(root->left);
        }
        if(root->right!=NULL){
            q.push(root->right);
        }
    }
}
```
## Go Lang
```go
import "container/list";

func levelOrder(root *TreeNode) [][]int {

    var q=list.New();
    var ans=[][]int{};
    if root==nil{
        return ans;
    }

    q.PushBack(root);
    for q.Len()>0{
        var n=q.Len();
        var brr=[]int{};
        for n>0{
            n-=1;
            var elm=q.Front();
            q.Remove(elm);
            var temp=elm.Value.(*TreeNode);
            brr=append(brr,temp.Val);
            if temp.Left!=nil{
                q.PushBack(temp.Left);
            }
            if temp.Right!=nil{
                q.PushBack(temp.Right);
            }
        }
        ans=append(ans,brr);
    }    
    return ans;
}
```
## Python
```py
from queue import Queue

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        ans=[]
        if root==None:
            return ans
        q=Queue()
        q.put(root)
        while q.qsize()>0:
            n=q.qsize()
            brr=[]
            while n>0:
                n-=1
                temp=q.get()
                brr.append(temp.val)
                if temp.left:
                    q.put(temp.left)
                if temp.right:
                    q.put(temp.right)
            ans.append(brr)
        
        return ans
```
