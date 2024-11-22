## Merge sort algo.
* [Striver](https://takeuforward.org/data-structure/merge-sort-algorithm/)
* Time:(NlogN)
* Space:O(N)
```cpp
void merge(int low,int mid,int high,vector<int>&arr){

    vector<int>temp;

    int l=low,r=mid+1;
    while(l<=mid and r<=high){
        if(arr[l]<=arr[r]){
            temp.push_back(arr[l]);
            l++;
        }else{
            temp.push_back(arr[r]);
            r++;
        }
    }

    while(l<=mid){
        temp.push_back(arr[l]);
        l++;
    }
    while(r<=high){
        temp.push_back(arr[r]);
        r++;
    }


    for(int i=low,j=0;i<=high;i++,j++){
        arr[i]=temp[j];
    }
}

void merge_sort(int low,int high,vector<int>&arr){

    if(low>=high)return;
    int mid=(low+high)/2;
    merge_sort(low,mid,arr);
    merge_sort(mid+1,high,arr);
    merge(low,mid,high,arr);
}
```
