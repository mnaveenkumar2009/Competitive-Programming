#include <bits/stdc++.h>
using namespace std;

#define int long long
int X, Y, l, r;

pair <int, int> f(int x, int i){
    pair <int, int> EX = {(X&l) * (Y&l), -l};
    for (; i >= 0; --i) {
        if (x + (1LL << i) - 1 < l) {
            x ^= (1LL << i);
            continue;
        }
        if ((X | Y) & (1LL << i)) {
            if((x ^ ((1LL << (i + 1)) - 1)) <= r){
                x ^= (1LL << i);
                continue;
            }
            if ((x ^ (1LL << i)) <= r)
                EX = max(EX, f(x ^ (1LL<<i), i - 1));
        }
    }
    return max(EX, {(X & x) * (Y & x), -x});
}

signed main(){
    cin >> X;
    while(cin >> X >> Y >> l >> r)
        cout << -f(0, log2l(r)).second << '\n';
}