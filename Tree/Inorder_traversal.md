### with recursion
```cpp
void dfs(TreeNode* root,vector<int>&arr){
      if(root==NULL)return;
      dfs(root->left,arr);
      arr.push_back(root->val);
      dfs(root->right,arr);
}
```
### with iteration
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
