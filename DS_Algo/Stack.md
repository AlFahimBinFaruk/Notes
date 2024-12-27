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
