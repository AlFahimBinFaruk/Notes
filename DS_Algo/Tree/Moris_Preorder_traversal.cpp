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
