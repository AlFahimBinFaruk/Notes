// struct TreeNode {
//     int data;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : data(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
// };


class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};



class Runner
{
    TreeNode *root;
public:
    void takeInput()
    {
        
        int rootData;
        cin >> rootData;
        
        root = new TreeNode(rootData);
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
    }

    
    void executeAndPrintOutput()
    {
        
    }
};



// from array
Node* createTree(vector<int>&arr){
    
    
    int i=0;
    queue<Node *>q;
    

    Node *root=new Node(arr[0]);
    q.push(root);
    

    while(!q.empty() and i<arr.size()/2){
        Node *cur=q.front();
        q.pop();
        int l=arr[2*i+1],r=arr[2*i+2];
        if(l!=-1){
            Node *left=new Node(l);
            cur->left=left;
            q.push(left);
        }else cur->left=NULL;

        if(r!=-1){
            Node *right=new Node(r);
            cur->right=right;
            q.push(right);
        }else cur->right=NULL;
        i++;
    }

    return root;

}
