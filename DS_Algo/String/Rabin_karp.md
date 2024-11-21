## Rabin Karp Algorithm.
* [Tushar Roy](https://youtu.be/H4VrKHVG5qI?si=hgcylhvnJ5si8FJo)
* Use cases: Uses Has for Multiple Text searching, Pattern matching.
* Time: O(N+M), worst: O(N*M)
* Space: O(N+M)
```cpp
vector<int> rabin_karp(string &p,string &t){

    int prime=31;
    int mod=1e9+9;

    int n=p.size(),m=t.size();
    vector<long long>p_pow(max(n,m));
    p_pow[0]=1;

    for(int i=1;i<p_pow.size();i++){
        p_pow[i]=(p_pow[i-1]*prime)%mod;
    }

    vector<long long>text_hash(m+1,0);
    for(int i=0;i<m;i++){
        text_hash[i+1]=(text_hash[i]+((t[i]-'a'+1)*p_pow[i]))%mod;
    }

    long long pattern_hash=0;
    for(int i=0;i<n;i++){
        pattern_hash=(pattern_hash+((p[i]-'a'+1)*p_pow[i]))%mod;
    }

    vector<int>occurances;

    for(int i=0;i+n<=m;i++){
        long long hash_to_comp=(text_hash[i+n]+mod-text_hash[i])%mod;
        // we are multiply and moduloing pattern hash again to handle the index alignment issue.
        if(hash_to_comp==(pattern_hash*p_pow[i]%mod)){
            occurances.push_back(i);
        }
    }

    return occurances;

}



signed main(){
    string t="sadbutsad",p="sad";
    debug(rabin_karp(p,t));
    
}
```
