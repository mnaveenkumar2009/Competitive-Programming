#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define mod 1000000007

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

int fact[500002];
 
int ncr(int n, int r){
    int ret = (fact[n] * pr(fact[r], mod - 2)) % mod;
    return (ret * pr(fact[n-r], mod - 2)) % mod;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;
    for(int i = 1; i <= 5e5 + 2; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    int n, m;
    cin >> n >> m;
    if(m < n){
        cout << "0\n";
        return 0;
    }

    int ans = 1;
    for(int i = 0; i < n; i++){
        ans = (ans * (m - i)) % mod;
    }
    ans = (ans * ans) % mod;
    int tem = ans;
    
    for(int i = 1; i <= n; i++){
        tem = (tem * pr(m - i + 1, mod - 2)) % mod;
        if(i&1)
            ans -= (tem * ncr(n, i)) % mod;
        else
            ans += (tem * ncr(n, i)) % mod;
        ans %= mod;
    }
    cout << (ans + mod) % mod << '\n';
}