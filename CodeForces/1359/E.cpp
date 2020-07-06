#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353

int fact[500005];

int pr(int x, int y) {
    int res = 1;
    x = x % mod;
    while (y > 0){
        if (y & 1)
            res = (res*x) % mod;
        y >>= 1;
        x = (x*x) % mod;  
    }
    return res;
}
int f2(int i, int j){
    if(i > j)return 0;
    int ret = (fact[j] * pr(fact[j - i] * fact[i], mod - 2))% mod;
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i < 500005; i++){
        fact[i] = (i * fact[i-1]) % mod;
    }
    // for(int i = 1; i < 10; i++){
    //     for(int j = 1; j < 10; j++){
    //         cout << i << ' ' << j << ' ' << f(i, j) << f2(i, j) << '\n';
    //     }
    //     // cout << '\n';
    // }
    int n, k;
    cin >> n >> k;
    int ans = 0;
    if(k == 1){
        cout << n << '\n';
        return 0;
    }
    for(int i = 1; i < n; i++){
        int c = 0;
        for(int j = 2; i * j <= n; j++){
            c++;
        }
        // a1 = i, a2 - an among c numbers
        ans += f2(k - 1, c);
        ans %= mod;
    }
    cout << ans << '\n';
}