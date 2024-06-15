//https://www.hackerrank.com/topics/heaps
/*
simple requirement is 
1. parent will always be smaller than child 
2. parent will always have min node.

left child can be greater than right child don't OC it.
*/
// this code is generated by GPT.

class MinHeap{
    private:
        vector<int>heap;
    
        // to make the valid structure.

        // O(logN)
        void heapify(int i){
    
            int smallest=i;
            int left=(2*i)+1;
            int right=(2*i)+2;
            
    
            int n=heap.size();
    
            if(left<n and heap[left]<heap[smallest]){
                smallest=left;
            }
    
            if(right<n and heap[right]<heap[smallest]){
                smallest=right;
            }
    
            if(smallest!=i){
                swap(heap[i],heap[smallest]);
                heapify(smallest);
            }
            
        }
    
        // return the parent index of i
        int parent(int i){
            return (i-1)/2;
        }

    public:


        // constructor
        MinHeap(){}

        // O(logN)
        void insert(int key){
    
            heap.push_back(key);
    
            int i=heap.size()-1;
    
            while(i>=0 and heap[i]<heap[parent(i)]){
                swap(heap[i],heap[parent(i)]);
                i=parent(i);
            }
        }
    
        // O(logN)
        int extractMin(){
    
            if(heap.empty()){
                throw runtime_error("Heap is empty");
            }
    
            int mn=heap[0];
    
            heap[0]=heap.back();
            heap.pop_back();
    
            heapify(0);
    
            return mn;
        }
    
    
        int getMin(){
            if(heap.empty()){
                throw runtime_error("Heap is empty");
            }
    
            return heap[0];
        }

        // O(logN)
        void decreaseKey(int i,int new_val){
            if(i>=heap.size()){
                throw runtime_error("Index don't exits.");
            }
    
            heap[i]=new_val;
            
            while(i>=0 and heap[i]<heap[parent(i)]){
                swap(heap[i],heap[parent(i)]);
                i=parent(i);
            }
        }
    

        // O(logN)
        void deleteKey(int i){
            if(i>=heap.size()){
                throw runtime_error("Index don't exits.");
            }
    
            decreaseKey(i,INT_MIN);
            extractMin();
        }
    
        bool isEmpty(){
            return heap.empty();
        }

};

signed main(){
    fastio();
    

    int n;cin>>n;

    MinHeap mnHeap;

    for(int i=0;i<n;i++){
        int nm;cin>>nm;

        mnHeap.insert(nm);

    }

    mnHeap.decreaseKey(1,3);

    print(mnHeap.extractMin());
    print(mnHeap.extractMin());
    
}
