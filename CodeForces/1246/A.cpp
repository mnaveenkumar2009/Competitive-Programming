#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, p, i;
    cin >> n >> p;
    for(i = 1; i < 5e6; i++){
        int n2 = n - p*i;
        if(n2 <= 0){
            i = 5e6;
            break;
        }
        if(__builtin_popcount(n2) <= i && n2 >= i){
            break;
        }
    }
    if(i==5e6)i = -1;
    
    cout << i << '\n';
}