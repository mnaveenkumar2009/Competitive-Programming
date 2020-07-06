#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int n, ans = 0;
	cin >> n;
	vector <int> adj[n + 1];
	for(int i = 0; i < n - 1; i++){
	    int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		int maxi = 0, c = 0;
		sort(adj[i].begin(), adj[i].end());
		for(int j:adj[i]){
			if(j < i){
				maxi = j;
				ans -= (maxi) * (n - i + 1);
			}
			else
			    break;
		}
		ans += (i) * (n - i + 1);
	}
	cout << ans;
}
