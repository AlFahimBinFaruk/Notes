* left->right->root

### Recurisive
  ```cpp
void dfs(TreeNode* root,vector<int>&arr){
    if(root==NULL){
        return;
    }

    dfs(root->left,arr);
    dfs(root->right,arr);
    
    arr.push_back(root->data);
}
```

### Iterative - 2 stack
```cpp
void sol(TreeNode* root,vector<int>&arr){
    stack<TreeNode *>s1,s2;
    if(root==NULL)return;

    s1.push(root);
    while(!s1.empty()){
        root=s1.top();
        s1.pop();
        s2.push(root);
        if(root->left!=NULL){
            s1.push(root->left);
        }
        if(root->right!=NULL){
            s1.push(root->right);
        }
    }

    while(!s2.empty()){
        arr.push_back(s2.top()->data);
        s2.pop();
    }
}
```

### Iterative - 1 stack
```cpp
// one
void sol(TreeNode* root,vector<int>&arr){
    stack<TreeNode *>s;
    
    while(!s.empty() || root!=NULL){
        if(root!=NULL){
            s.push(root);
            root=root->left;
        }else{
            TreeNode* cur = s.top()->right;
            if(cur==NULL){
                cur=s.top();
                s.pop();
                arr.push_back(cur->data);
                while(!s.empty() && cur==s.top()->right){
                    cur=s.top();
                    s.pop();
                    arr.push_back(cur->data);
                }
            }else root=cur;
        }
    }
}
// two
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>arr;
        vector<TreeNode*>brr;
        
        while(true){
            if(root){
                brr.push_back(root);
                root=root->left;
            }else if(brr.size()>0){
                
                TreeNode* temp=NULL;

                while(brr.size()>0 and brr.back()->right==temp){
                    arr.push_back(brr.back()->val);
                    temp=brr.back();
                    brr.pop_back();
                }
                if(brr.size()>0){
                    root=brr.back()->right;
                }
            }else break;
        }
       
        
        
        return arr;
    }
};
```
## Go
### Recursion
```go
func dfs(root *TreeNode,ans *[]int){
    if root==nil{
        return
    }
    dfs(root.Left,ans)
    dfs(root.Right,ans)
    *ans=append(*ans,root.Val)
}
func postorderTraversal(root *TreeNode) []int {
    ans:=[]int{}
    dfs(root,&ans)
    return ans
}
```
### Iteration
```go
func postorderTraversal(root *TreeNode) []int {
    ans:=[]int{}
    st:=[]*TreeNode{}
    for true{
        if root!=nil{
            st=append(st,root)
            root=root.Left
        }else if len(st)>0{
            var prev *TreeNode=nil
            for len(st)>0 && st[len(st)-1].Right==prev{
                prev=st[len(st)-1]
                st=st[:len(st)-1]
                ans=append(ans,prev.Val)
            }
            if len(st)==0{
                break
            }else{
                root=st[len(st)-1].Right
            }
        }else{
            break
        }
    }
    return ans
}
```
## Python
### Iteration
```py
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]
        st=[]
        while True:
            if root:
                st.append(root)
                root=root.left
            elif len(st)>0:
                prev=None
                while len(st)>0 and st[len(st)-1].right==prev:
                    prev=st.pop()
                    ans.append(prev.val)
                if len(st)==0:break
                else: root=st[len(st)-1].right
            else: break
        return ans
```
