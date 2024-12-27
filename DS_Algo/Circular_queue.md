## Circular Queue.
* [GFG](https://www.geeksforgeeks.org/cpp-program-to-implement-circular-queue/)
* Circular queue(same as queue) is mainly useful when you are using array to implement Queue because it can do dequeue operation in O(1) without using extra space,but if you are using LL to implement queue it's of no use.
### With Array
```cpp
const int MAX_SIZE=33;

class Queue{
    private:
        int arr[MAX_SIZE];//main arr
        int front;
        int rear;
    public:
        Queue(){
            front=0;
            rear=0;
        }

        bool isEmpty(){
            return front==rear;
        }

        bool isFull(){
            if((rear+1)%MAX_SIZE==front){
                return true;
            }
            return false;
        }

        void enqueue(int val){
            if(!isFull()){
                rear=(rear+1)%MAX_SIZE;
                arr[rear]=val;
            }
        }

        void dequeue(){
            if(!isEmpty()){
                front=(front+1)%MAX_SIZE;
            }
        }

        int peek(){
            return arr[(front+1)%MAX_SIZE];
        }
};

int main(){

    Queue q=Queue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    while(!q.isEmpty()){
        cout<<q.peek()<<" ";
        q.dequeue();
    }

    return 0;
}
```
