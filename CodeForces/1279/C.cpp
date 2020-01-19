#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll N = 2e6+2;
ll n = N;
ll tree[2 * N];

void modify(ll p, ll value) {
    for (tree[p += n] = value; p > 1; p >>= 1)
    	tree[p>>1] = min(tree[p], tree[p^1]);
}
ll query(ll l, ll r) {
    ll res = 1e9;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = min(res, tree[l++]);
        if (r&1) res = min(tree[--r], res);
    }
    return res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int ans = m;
		int a[m], b[n], p[n], F[n + 1];
		F[n] = 0;
		for(int i = 0; i < n; i++){
			F[i] = 0;
			p[i] = n;
			cin >> b[i];
		}
		for(int i = 0; i < m; i++){
			cin >> a[i];
			p[a[i] - 1] = i;
		}
		for(int i = 0; i < n; i++){
			b[i] = p[b[i] - 1];
			F[b[i]]++;
			modify(i, b[i]);
			// cout << b[i] << ' ';
		}
		// cout << '\n';
		for(int i = 1; i <= n; i++)
			F[i] += F[i-1];
		for(int i = 0; i < n; i++){
			if(query(i + 1, n) > b[i]){
				// number of elements > b[i] before i
				ans += 2 * (F[n] - F[b[i]] - (n - i - 1));
			}
		}
		cout << ans << '\n';
	}	
}