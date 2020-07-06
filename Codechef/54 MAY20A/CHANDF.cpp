#include <bits/stdc++.h>
using namespace std;

#define int long long

pair <int, int> f(int l, int r, int X, int Y, int x, int i){
    // cout << l << ' ' << r << ' ' << x << ' ' << i << '\n';
    int n = X | Y, n2 = X & Y;
    pair <int, int> EX = {-1, -1};
    for (; i >= 0; --i) {
        if ((x + (1LL << i) - 1 < l)) {
            x ^= (1LL << i);
            continue;
        }
        if ((n & (1LL << i))) {
            if ((x ^ (1LL << i)) <= r){
                int YY = (x ^ (1LL << i));
                YY ^= (1LL << i) - 1;
                if(YY <= r){
                    x ^= (1LL << i);
                    continue;
                }
                EX = f(l, r, X, Y, x ^ (1LL<<i), i - 1);
            }
        }
    } 
    int L = (X & x) * (Y & x);
    if(EX.first > L){
        x = EX.second;
        L = EX.first;
    }
    if(L == 0){
        x = l;
    }
    return {L, x};
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        cout << (f(l, r, x, y, 0, log2l(r))).second << '\n';
    }
}