#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0, cur_r = -1e15;
    cin >> n;
    pair <int, int> X[n];
    for(int i = 0; i < n; i++){
        int x, d;
        cin >> x >> d;
        X[i] = {x + d, x - d};
    }
    sort(X, X + n);
    for(int i = 0; i < n; i++){
        if(X[i].second >= cur_r){
            cur_r = X[i].first;
            ans++;
        }
    }
    cout << ans << '\n';
}