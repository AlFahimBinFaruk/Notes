## Queue 
### With Array
```cpp
class Queue{
    private:
        int *arr;//main arr
        int size;
        int capacity;
        int frontInd;

        void resize(int newCapacity){
            int *newArr=new int[newCapacity];
            for(int i=0;i<size;i++){
                newArr[i]=arr[i];
            }
            delete[] arr;
            arr=newArr;
            capacity=newCapacity;
        }
    public:
        Queue(){
            arr=NULL;
            size=0;
            frontInd=0;
            capacity=0;
        }

        void enqueue(int val){
            if(size>=capacity){
                int newCapacity=(capacity==0)?1:(capacity*2);
                resize(newCapacity);
            }
            arr[size]=val;
            size++;
        }

        void dequeue(){
            if(size==0){
                return;
            }
            for(int i=1;i<size;i++){
                arr[i-1]=arr[i];
            }
            size--;
        }

        int front(){
            if(frontInd<size){
                return arr[frontInd];
            }
            return -1;
        }

        bool isEmpty(){
            return size<=0;
        }

        ~Queue(){
            delete[] arr;
        }
};

int main(){

    Queue q=Queue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.dequeue();
    }

    return 0;
}
```
