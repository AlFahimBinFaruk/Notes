## Quick sort algo.
* [Striver](https://takeuforward.org/data-structure/quick-sort-algorithm/)
* Time : O(N*logN)/ O(N^2)when arr is already sorted.
* Space: O(1)+O(N) recursion stack complexity.


```cpp
// int partition(vector<int>&arr,int low,int high){
//     int pivot=arr[low];
//     int i=low,j=high;

//     while(i<j){
//         while(arr[i]<=pivot and i<high){
//             i++;
//         }

//         while(arr[j]>=pivot and j>low){
//             j--;
//         }
//         if(i<j){
//             swap(arr[i],arr[j]);
//         }
//     }

//     swap(arr[low],arr[j]);

//     return j;

// }

int partition(vector<int>&nums,int low,int high){
    int pivot=nums[low];
    int l=low+1,r=high;
    while(l<=r){
            
        if(nums[l]>pivot and nums[r]<pivot){
            swap(nums[l],nums[r]);
            l++,r--;
        }
        if(nums[l]<=pivot){
            l++;
        }
        if(nums[r]>=pivot){
            r--;
        }
    }
    swap(nums[low],nums[r]);
    return r;
}


void qs(vector<int>&arr,int low,int high){
    if(low<high){
        int pt=partition(arr,low,high);
        qs(arr,low,pt-1);
        qs(arr,pt+1,high);
    }
}


int main() {

    vector<int>arr={4,6,2,5,7,7,1,3};
    qs(arr,0,arr.size()-1);

    debug(arr);
    
    return 0;
}
```
