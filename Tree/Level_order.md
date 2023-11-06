* root->left->right
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
