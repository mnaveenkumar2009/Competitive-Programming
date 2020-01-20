#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007

int nc2(int n){
	int ret = n*(n-1);
	ret /= 2;
	ret %= mod;
	return ret;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, ans = 0;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			a[i] = __builtin_popcount(a[i])%2;
		}
		int odd = 0, even = 0;
		for(int i = 0; i < n; i++){
			// cout << odd << even <<'\n';
			if(!a[i])
				ans = (ans + odd * even)%mod;
			if(a[i])
				ans = (ans + nc2(odd) + nc2(even))%mod;
			odd += a[i];
			even += 1-a[i];
			odd %= mod;
			even %= mod;
		}
		// cout << odd << even <<'\n';
		cout << ans  << '\n';
	}
}