## Radix Sort Algo.
* [Farhan hasan](https://www.youtube.com/watch?v=cJYG72LWLIg)
* [Counting sort](https://www.youtube.com/watch?v=uvOe510RmWc)
* Time: O(d*(n+b))
* Space: O(n+b)
```cpp
int getMax(vector<int>&arr){
    int mx=0;
    for(int cur:arr){
        mx=max(mx,cur);
    }
    return mx;
}

void counting_sort(vector<int>&arr,int exp){
    int n=arr.size();

    int count_arr[10]={0};
    for(int i=0;i<n;i++){
        count_arr[(arr[i]/exp)%10]++;
    }

    for(int i=1;i<10;i++){
        count_arr[i]+=count_arr[i-1];
    }
    
    vector<int>output(n);
    for(int i=n-1;i>=0;i--){
        int digit=(arr[i]/exp)%10;
        count_arr[digit]-=1;
        int ind=count_arr[digit];
        output[ind]=arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}

void radix_sort(vector<int>&arr){

    int mx=getMax(arr);

    for(int exp=1;(mx/exp)>0;exp*=10){
        counting_sort(arr,exp);
    }

}
signed main(){
    fastio();
    
    vector<int>arr={802, 2, 24, 45, 66, 170, 75, 90};
    radix_sort(arr);
    debug(arr);
    
}
```
