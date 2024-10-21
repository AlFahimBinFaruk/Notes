/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int>ans;

        
        /*
        original format have to be restored.
        */
        while(root){
            
            
            if(root->left){
                TreeNode* temp=root->left;
                while(true){
                    if(temp->right and temp->right==root){
                        ans.push_back(root->val);
                        root=root->right;

                        temp->right=NULL;
                        break;
                    }else if(temp->right){
                        temp=temp->right;
                    }else{
                        TreeNode* temp2=root;
                        root=root->left;
                        temp->right=temp2;
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
