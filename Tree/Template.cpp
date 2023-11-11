#include <bits/stdc++.h>
using namespace std;



#define nl "\n"
#define print(x) cout<<x<<nl
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#ifndef ONLINE_JUDGE
#include "../debug.h"
#else
#define debug(x)
#endif


/*--------------------------------------------------------
                                    Code starts from here.
--------------------------------------------------------------------------------------*/



class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};





TreeNode* createTree(){

    int rootData;
    cin >> rootData;

    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        int lc, rc;
        cin >> lc;
        if (lc != -1)
        {
            TreeNode *leftNode = new TreeNode(lc);
            curr->left = leftNode;
            q.push(leftNode);
        }
        cin >> rc;
        if (rc != -1)
        {
            TreeNode *rightNode = new TreeNode(rc);
            curr->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}




signed main(){
    fastio();
    


    TreeNode* root=createTree();

    

    
}
