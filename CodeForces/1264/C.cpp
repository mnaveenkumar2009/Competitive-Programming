#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 998244353

const int N = 2e6 + 2;

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
ll inv(int n){
	return pr(n, mod - 2);
}

signed main(){
    int n, q;
    cin >> n >> q;
    int a[n], b[n], sum[n];

    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	b[i] = (a[i]);
    	if(i)
    		b[i] = (b[i] * b[i-1])%mod;
    	sum[i] = inv(b[i]);
    	if(i)
    		sum[i] += sum[i-1];
    	cout << sum[i] << ' ';
    }
    cout << '\n';
    vector<bool> v(n, 0);
    int cur = sum[n-1];
    while(q--){
    	int x;
    	cin >> x;
    	int upd = sum[n-1];
    	if(x - 1)
    		upd = sum[x - 2];
    	if(v[x-1]){
    		upd = inv(upd);
    	}
    	cout << cur << '\n';
    }

}