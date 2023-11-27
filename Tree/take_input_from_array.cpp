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

class Node {
        public :
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
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

signed main(){
    fastio();
    
    int n;cin>>n;
    vector<int>arr(n);
    for(auto &i:arr)cin>>i;

    Node* head=createTree(arr);

    
}
