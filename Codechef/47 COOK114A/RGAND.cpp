#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int i = 62; i >= 0; i--){
            if(l & (1LL << i)){
                int rem = (1LL << i) - (l & ((1LL << i) - 1));
                rem = min(rem, r - l + 1);
                rem %= mod;
                ans += (rem) * ((1LL << i) % mod);
                ans %= mod;
            }
        }
        cout << ans << '\n';
    }
}