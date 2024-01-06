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
class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr){};
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};


Node* createNode(){
    int nm;cin>>nm;
    Node* head=new Node(nm);
    queue<Node*>q;
    q.push(head);
    while(!q.empty()){
        Node* cur=q.front();
        q.pop();
        cin>>nm;
        if(nm!=-1){
            cur->next=new Node(nm);
            q.push(cur->next);
        }else cur->next=NULL;
    }

    return head;
}

signed main(){
    fastio();

    Node* head=createNode();

    while(head){
        print(head->data);
        head=head->next;
    }
    



    
}
