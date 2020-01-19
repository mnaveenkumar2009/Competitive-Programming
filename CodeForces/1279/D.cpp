#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 998244353 
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
	int n;
	cin >> n;
	map <int, int> M;
	int Siz[n];
	vector <int> a[n];
	int ans = 0, tem = pr(n * n, mod - 2);
	for(int i = 0; i < n; i++){
		int S;
		cin >> S;
		Siz[i] = S;
		for(int j = 0; j < S; j++){
			int x;
			cin >> x;
			M[x]++;
			a[i].push_back(x);
		}
	}
	for(int i = 0; i < n; i++){
		int temp = (tem * pr(Siz[i], mod - 2)) % mod;
		for(auto j : a[i])
			ans = (ans + (M[j] * temp))% mod;
	}
	cout << ans << '\n';
}