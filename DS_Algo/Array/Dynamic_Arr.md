## Dynamic Array/ Vector
```cpp
class DynamicArray{
    private:
        int *arr;//main arr
        int size;
        int capacity;

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

        DynamicArray(){
            arr=NULL;
            size=0;
            capacity=0;
        }

        void push_back(int val){
            if(size>=capacity){
                int newCapacity=(capacity==0)?1:(capacity*2);
                resize(newCapacity);
            }
            arr[size]=val;
            size++;
        }

        void pop_back(){
            if(size>0){
                size--;
            }
        }

        int getVal(int ind){
            if(ind>=size){
                return -1;
            }
            return arr[ind];
        }

        void updateInd(int ind,int newVal){
            if(ind<size){
                arr[ind]=newVal;
            }
        }


        ~DynamicArray(){
            delete[] arr;
        }
        

};

int main(){

    DynamicArray arr=DynamicArray();
    arr.push_back(1);
    arr.push_back(2);

    arr.updateInd(1,3);

    for(int i=0;i<2;i++){
        cout<<arr.getVal(i)<<" ";
    }

    return 0;
}
```
