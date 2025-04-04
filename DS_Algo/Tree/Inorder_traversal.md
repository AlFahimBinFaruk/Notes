* left->root->right.
* Inorder traversal always gives you an sorted array.
### Recursion
```cpp
void dfs(TreeNode* root,vector<int>&arr){
      if(root==NULL)return;
      dfs(root->left,arr);
      arr.push_back(root->val);
      dfs(root->right,arr);
}
```
### Iteration
```cpp
void sol(TreeNode* root,vector<int>&arr){
    stack<TreeNode *>s;
    while(true){
        if(root!=NULL){
            s.push(root);
            root=root->left;
        }else{
            if(s.empty())break;

            root=s.top();
            s.pop();
            arr.push_back(root->data);
            root=root->right;
        }
    }
    
}
```
### Moris inorder traversal
```cpp
while (root){

    if (root->left){
        TreeNode *temp = root->left;
        while (true){
            if (temp->right and temp->right == root){
                cout<<root->val<<" ";
                root = root->right;
                temp->right = NULL;
                break;
            }
            else if (temp->right){
                temp = temp->right;
            }
            else{
                TreeNode *temp2 = root;
                root = root->left;
                temp->right = temp2;
                break;
            }
        }
    }
    else{

        cout<<root->val<<" ";
        root = root->right;
    }
}
```
## Python
### Recursion
```py
class Solution:
    def dfs(self,cur,ans):
        if cur==None:
            return
        self.dfs(cur.left,ans)
        ans.append(cur.val)
        self.dfs(cur.right,ans)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans=[]
        self.dfs(root,ans)
        return ans
```
### Iteration
```py
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        st=[]
        ans=[]
        while True:
            if root:
                st.append(root)
                root=root.left
            elif len(st)>0:
                cur=st.pop()
                ans.append(cur.val)
                root=cur.right
            else: break
        return ans
```

## Go
### Recursion
```go
func dfs(root *TreeNode,ans *[]int){
    if root==nil{
        return
    }
    dfs(root.Left,ans)
    *ans=append(*ans,root.Val)
    dfs(root.Right,ans)
}
func inorderTraversal(root *TreeNode) []int {
    ans:=[]int{}
    dfs(root,&ans)
    return ans
}
```
### Iteration
```go
func inorderTraversal(root *TreeNode) []int {
    ans:=[]int{}
    st:=[]*TreeNode{}
    for true{
        if root!=nil{
            st=append(st,root)
            root=root.Left
        }else if len(st)>0{
            cur:=st[len(st)-1]
            st=st[:len(st)-1]
            ans=append(ans,cur.Val)
            root=cur.Right
        }else{
            break
        }
    }
    return ans
}
```
