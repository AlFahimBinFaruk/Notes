## Min Heap
* [HackerRank](https://www.hackerrank.com/topics/heaps)


```cpp
class MinHeap{
    vector<int>heap;
    
    //O(logN)
    void heapify(int i){
        
        int n=heap.size();

        int smallest=i;
        int left=(2*i)+1;
        int right=(2*i)+2;
        
        if(left<n and heap[left]<heap[smallest]){
            smallest=left;
        }
        if(right<n and heap[right]<heap[smallest]){
            smallest=right;
        }

        if(i!=smallest){
            swap(heap[smallest],heap[i]);
            heapify(smallest);
        }
    }

    int parent(int i){
        return (i-1)/2;
    }

    public:
        //O(logN)
        void push(int val){
            heap.push_back(val);
            int i=heap.size()-1;

            while(i>=0 and heap[i]<heap[parent(i)]){
                swap(heap[i],heap[parent(i)]);
                i=parent(i);
            }
        }

        int getMin(){
            if(heap.size()==0){
                throw runtime_error("Heap is empty.");
            }
            return heap[0];
        }

        int extractMin(){
            if(heap.size()==0){
                throw runtime_error("Heap is empty.");
            }
            int mn= heap[0];
            heap[0]=heap.back();
            heap.pop_back();
            heapify(0);

            return mn;
        }

        //O(logN)
        void changeVal(int i,int new_val){
            if(i>=heap.size()){
                throw runtime_error("Heap is empty.");
            }
            heap[i]=new_val;

            while(i>=0 and heap[i]<heap[parent(i)]){
                swap(heap[i],heap[parent(i)]);
                i=parent(i);
            }
        }

        void deleteKey(int i){
            if(i>=heap.size()){
                throw runtime_error("Heap is empty.");
            }
            changeVal(i,INT_MIN);
            extractMin();
        }

};

signed main(){
    fastio();
    

    int n;cin>>n;
    

    MinHeap mnHeap;

    for(int i=0;i<n;i++){
        int nm;cin>>nm;

        mnHeap.push(nm);

    }

    // mnHeap.changeVal(2,0);

    print(mnHeap.extractMin());
    // print(mnHeap.extractMin());
    // print(mnHeap.extractMin());
    // print(mnHeap.extractMin());
    // print(mnHeap.extractMin());
    
}
```
