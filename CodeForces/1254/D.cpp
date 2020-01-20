#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, m;
	cin >> n >> m;
	while(m--){
		int u, v;
		cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			if(i < maxi)
				ans++;
			dfs(i);
		}
	}
	cout << ans << '\n';
}