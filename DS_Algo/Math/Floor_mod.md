1. -11%(1e9+7)=-11 but the ans is 999999996
so moding negative numbers dosen't work properly in cpp so, the solution is using floor mod
```cpp
int floorMod(int a, int mod){
     
    int q = (int)floor((double)a / mod);
 
    return a - mod * q;
}

```
* (gfg)[https://www.geeksforgeeks.org/modulo-operations-in-programming-with-negative-results/]
