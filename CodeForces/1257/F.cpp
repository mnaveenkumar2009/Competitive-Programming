#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, a[1000006];
    cin >> n;
    map < vector<int>, int> XXX;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int mask = 0; mask < (1LL<<15); mask++){
        vector<int> c(n, -__builtin_popcount((a[0]&((1<<15) - 1))^mask));
        for(int i = 0; i < n; i++)
            c[i] += __builtin_popcount((a[i]&((1<<15) - 1))^mask);
        XXX[c] = mask + 1;
    }
    for(int mask = 0; mask < (1LL<<15); mask++){
        vector <int> c(n, (__builtin_popcount((a[0] >> 15)^mask)));
        for(int i = 0; i < n; i++)
            c[i] -= (__builtin_popcount((a[i] >> 15)^mask));
        if(XXX[c]){
            cout << ((mask << 15) | (XXX[c] - 1)) << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}