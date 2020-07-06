#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int x = log2l(n);
        if((1LL << x) == n){
            cout << "-1\n";
            continue;
        }
        int ans = -1, cur = 1;
        while(n){
            ans += ((n/2) + (n&1)) * cur;
            cur *= 2;
            n /= 2;
        }
        cout << ans << '\n';
    }
}