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
```
