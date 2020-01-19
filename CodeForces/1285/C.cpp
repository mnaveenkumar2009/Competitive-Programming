#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x;
    cin >> x;
    pair <int, int> X = {1, x};
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0 && __gcd(i, x/i) == 1){
            X = {i, x/i};
        }
    }
    cout << X.first << ' ' << X.second << '\n';
}