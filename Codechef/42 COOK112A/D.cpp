#include <bits/stdc++.h>
using namespace std;
#define int long long
int maxi = -1;
bool vis[200005];
vector <int> adj[200005];
void dfs(int node){
	maxi = max(maxi, node);
	vis[node] = 1;
	for(auto child:adj[node])
		if(!vis[child])
			dfs(child);
}

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