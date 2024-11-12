* If we don't prepocessed the string it will not work for Test cases like : abba where we have even lenght palindrome.
because then we have to handle for even and odd separately.
```cpp
// O(2N)=> O(N)
// for both even and odd length.
int manacher_algo(string &s){

    int n=s.size();
    int P[n];
    memset(P,0,sizeof(P));
    
    int C=0,R=0;
    int mx=0;

    

    for(int i=1;i<s.size()-1;i++){
        
        // the concept of mirroring is main thing that reduce the time complexity from O(N^2) -> O(N) as we don't have to calculate the lenght we have calcualte before.
        if(i<R){
            int mirr=(2*C)-i;
            //if i is center then we can at max expand it till right boundry,it can happen that mirror for i expand beyond the current boundry range from left so thats why we are checking it.
            P[i]=min(R-i,P[mirr]);
        }

        //check if we can expand further 
        while(s[i+(1+P[i])]==s[i-(1+P[i])]){
            P[i]++;
        }

        //if we can only expand beyond cur right boundry only then change it.
        if((i+P[i])>R){
            C=i;
            R=i+P[i];
        }

        mx=max(mx,P[i]);
    }

    return mx;
}
signed main(){
    fastio();
    
    string s="aaaa";
    string nw="$";
    for(int i=0;i<s.size();i++){
        nw+="#";
        nw+=s[i];
    }
    nw+="#";
    nw+="@";

    


    print(manacher_algo(nw));

}
```
