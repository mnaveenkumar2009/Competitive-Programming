#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll N = 2e5+2;
ll n;
ll tree[2 * N];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int m, q;
		cin >> n >> m >> q;
		vector <int> a(n + 1, 0);
		for(int i = 0; i < n; i++)
			tree[i] = tree[n+i] = 0;
		int L[m], R[m], cost[m];
		for(int i = 0; i < m; i++){
			cin >> L[i] >> R[i] >> cost[i];
			L[i]--;
			R[i]--;
		}
		while(q--){
			int l, r;
			cin >> l >> r;
			vector <int> negat;
			// cout << l << ' ' << r << '\n';
			for(int i = l - 1; i <= r - 1; i++){
				if(cost[i] == 0)continue;
				negat.push_back(R[i] + 1);
				negat.push_back(L[i]);
				a[R[i] + 1] -= cost[i];
				a[L[i]] += cost[i];
				if(R[i] != n-1)
					tree[ n + R[i] + 1] -= cost[i];
				tree[n + L[i]] += cost[i];
			}
			negat.push_back(n);
			sort(negat.begin(), negat.end());
			int D = 0;
			for(int i = 0; i < negat.size() - 1; i++){
				// int D = query(0, negat[i] + 1);
				if(negat[i] != negat[i+1])
					D += tree[n+negat[i]];
				if(D < 0 && negat[i] != negat[i+1]){
					// cout << q << ' ' << negat[i] << D << '\n';
					a[negat[i+1]] -= -D;
					a[negat[i]] += -D;
				}
			}
			for(auto i:negat)
				tree[i+n] = 0;
		}
		for(int i = 1; i < n; i++)
			a[i] += a[i-1];
		for(int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
}