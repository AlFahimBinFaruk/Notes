## Z Function
* [Tushar roy](https://www.youtube.com/watch?v=CpZh4eF8QBw)
* Use cases: Text searching, Pattern matching
* Time: O(2L)~O(L)
* Space: O(N+M)
```cpp
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

signed main(){
    string a,b;cin>>a>>b;
    //finding b inside a.
    b+="$"
    b+=a;
    z_function(b);
}
```
