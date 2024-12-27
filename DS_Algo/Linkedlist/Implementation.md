## Singly
```cpp
class Node {
public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        Node* Head=new Node(arr[0]);
        Node* temp=Head;

        int n=arr.size();
        
        for(int i=1;i<n;i++){
            temp->next=new Node(arr[i]);
            temp=temp->next;
        }
        
        return Head;
    }
};
```

## Doubly
```cpp
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node(){
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value){
        prev = NULL;
        data = value;
        next = NULL;
    }
};

class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        
        Node* Head=new Node(arr[0]);
        Node* temp=Head;
        
        int n=arr.size();
        
        for(int i=1;i<n;i++){
            temp->next=new Node(arr[i]);
            temp->next->prev=temp;
            temp=temp->next;
        }
        
        return Head;
    }
};
```
