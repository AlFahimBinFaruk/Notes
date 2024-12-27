## Stack
### With Array
```cpp
#include <iostream>
#include <vector>
using namespace std;


class Stack{
    private:
        int *arr;//main arr
        int topInd;
        int capacity;

        void resize(int newCapacity){
            int *newArr=new int[newCapacity];
            for(int i=0;i<topInd;i++){
                newArr[i]=arr[i];
            }
            delete[] arr;
            arr=newArr;
            capacity=newCapacity;
        }
    public:

        Stack(){
            arr=NULL;
            topInd=-1;
            capacity=-1;
        }

        void push(int val){
            topInd++;
            if(topInd>=capacity){
                int newCapacity=(capacity==-1)?1:(capacity*2);
                resize(newCapacity);
            }
            arr[topInd]=val;
        }

        void pop(){
            if(topInd>=0){
                topInd--;
            }
        }

        int top(){
            if(topInd<0){
                return -1;
            }
            return arr[topInd];
        }

        int size(){
            return topInd;
        }

        

        ~Stack(){
            delete[] arr;
        }
        

};

int main(){

    Stack st=Stack();
    st.push(1);
    st.push(2);
    st.push(3);
    while(st.size()!=-1){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
```


### With Linked List
```cpp
class Node{
    public:
        int val;
        Node* next;
        Node(){
            val=0;
            next=NULL;
        }
        Node(int newVal){
            val=newVal;
            next=NULL;
        }
};

class Stack{
    private:
        Node* nw;
    
    public:
        Stack(){
            nw=NULL;
        }

        void push(int val){
            Node* temp=new Node(val);
            temp->next=nw;
            nw=temp;
        }

        void pop(){
            if(nw!=NULL){
                Node* temp=nw->next;
                delete nw;
                nw=temp;
            }
        }

        int top(){
            if(nw!=NULL){
                return nw->val;
            }
            return -1;
        }

        bool size(){
            return nw!=NULL;
        }

        ~Stack(){
            delete nw;
        }
};

int main(){

    Stack st=Stack();
    st.push(1);
    st.push(2);
    st.push(3);
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
```
