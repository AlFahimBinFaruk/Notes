* root->left->right.
### Recursive
```cpp
void dfs(TreeNode<int>*root,vector<int>&arr){
    if(root==NULL)return;
    arr.push_back(root->data);
    dfs(root->left,arr);
    dfs(root->right,arr);
}
```

### Iterative
```cpp
void sol(TreeNode<int>* root,vector<int>&arr){
    stack<TreeNode<int>* >s;
    if(root==NULL)return;
    
    s.push(root);
    while(!s.empty()){
        root=s.top();
        arr.push_back(root->data);
        s.pop();

        if(root->right!=NULL){
            s.push(root->right);
        }
        if(root->left!=NULL){
            s.push(root->left);
        }
    }
}
```
### Moris Preorder traversal
```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int>ans;

        while(root){
            if(root->left){
                TreeNode* temp=root->left;
                while(true){
                    if(temp->right and temp->right==root){
                        temp->right=NULL;
                        root=root->right;
                        break;
                    }else if(temp->right){
                        temp=temp->right;
                    }else{
                        temp->right=root;
                        ans.push_back(root->val);
                        root=root->left;
                        break;
                    }
                }
            }else{
                ans.push_back(root->val);
                root=root->right;
            }
        }

        return ans;
        
    }
};
```

## Go Lang
### DFS
```go
func dfs(root *TreeNode,arr *[]int){
    if(root==nil){
        return;
    }
    *arr=append(*arr,root.Val);
    dfs(root.Left,arr);
    dfs(root.Right,arr);
}
func preorderTraversal(root *TreeNode) []int {
    var arr=[]int{};
    dfs(root,&arr);
    return arr;
}
```
### BFS
```go
import "container/list"

func preorderTraversal(root *TreeNode) []int {
    
    var st=list.New();
    var ans=[]int{};
    if root==nil{
        return ans;
    }
    st.PushBack(root);
    for st.Len()>0{
        var elm=st.Back();
        st.Remove(elm);

        var temp *TreeNode=elm.Value.(*TreeNode);
        ans=append(ans,temp.Val);
        if temp.Right!=nil{
            st.PushBack(temp.Right);
        }
        if temp.Left!=nil{
            st.PushBack(temp.Left);
        }
        
    }
    return ans;
}
```
