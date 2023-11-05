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
