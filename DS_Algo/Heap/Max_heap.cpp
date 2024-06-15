class MaxHeap{
    private:
        vector<int>heap;
    
        // to make the valid structure.
        void heapify(int i){
    
            int largest=i;
            int left=(2*i)+1;
            int right=(2*i)+2;
            
    
            int n=heap.size();
    
            if(left<n and heap[left]>heap[largest]){
                largest=left;
            }
    
            if(right<n and heap[right]>heap[largest]){
                largest=right;
            }
    
            if(largest!=i){
                swap(heap[i],heap[largest]);
                heapify(largest);
            }
            
        }
    
        // return the parent index of i
        int parent(int i){
            return (i-1)/2;
        }

    public:


        // constructor
        MaxHeap(){}
    
        void insert(int key){
    
            heap.push_back(key);
    
            int i=heap.size()-1;
    
            while(i>=0 and heap[i]>heap[parent(i)]){
                swap(heap[i],heap[parent(i)]);
                i=parent(i);
            }
        }
    
    
        int extractMax(){
    
            if(heap.empty()){
                throw runtime_error("Heap is empty");
            }
    
            int mx=heap[0];
    
            heap[0]=heap.back();
            heap.pop_back();
    
            heapify(0);
    
            return mx;
        }
    
    
        int getMax(){
            if(heap.empty()){
                throw runtime_error("Heap is empty");
            }
    
            return heap[0];
        }
    
        void decreaseKey(int i,int new_val){
            if(i>=heap.size()){
                throw runtime_error("Index don't exits.");
            }
    
            heap[i]=new_val;
            
            heapify(i);
        }


        void increaseKey(int i,int new_val){
            if(i>=heap.size()){
                throw runtime_error("Index don't exits.");
            }
    
            heap[i]=new_val;
            
            while(i>=0 and heap[i]>heap[parent(i)]){
                swap(heap[i],heap[parent(i)]);
                i=parent(i);
            }
        }
    
    
        void deleteKey(int i){
            if(i>=heap.size()){
                throw runtime_error("Index don't exits.");
            }
    
            decreaseKey(i,INT_MAX);
            extractMax();
        }
    
        bool isEmpty(){
            return heap.empty();
        }

};

signed main(){
    fastio();
    

    int n;cin>>n;

    MaxHeap mxHeap;

    for(int i=0;i<n;i++){
        int nm;cin>>nm;

        mxHeap.insert(nm);

    }

    mxHeap.decreaseKey(1,3);

    mxHeap.increaseKey(1,98);

    print(mxHeap.extractMax());
    print(mxHeap.extractMax());
    
}
