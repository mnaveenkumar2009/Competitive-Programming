#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
int mod;
ll pr(ll x, ll y)
{
    ll res = 1; 
    x = x % mod;
    while (y > 0){
        if (y & 1)
            res = (res*x) % mod;
        y >>= 1;
        x = (x*x) % mod;  
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin >> n >> mod;
    int fact[n + 3];
    fact[0] = 1;
    for(int i = 1; i < n + 2; i++)
    	fact[i] = (fact[i-1] * i) % mod;
    if(n == 1){
    	cout << 1%mod << '\n';
    	return 0;
    }
    for(int i = 1; i <= n; i++){
    	// siz i
    	// nCi * fact[i] * (n - i + 1)
    	int x = fact[i];
    	x %= mod;
    	x *= n - i + 1;
    	x %= mod;
    	x *= fact[n - i + 1];
    	x %= mod;
    	// cout <<x << '\n';
    	ans = (ans + x) % mod;
    }
    cout << ans << '\n';
}