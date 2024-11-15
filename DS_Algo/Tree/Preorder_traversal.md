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
