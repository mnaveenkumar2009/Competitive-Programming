#include <bits/stdc++.h>
using namespace std;
#define int long long

int sz[100005], par[10005];

int dfs(int node, int par){
	
	sz[node] = 1;
	for(auto child:adj[node]){
		if(par != child)
			sz[node] += dfs(child, node);
	}
	return sz[node];
}

signed main(){
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u-1].insert(v-1);
		adj[v-1].insert(u-1);
	}
	dfs(0);
	for(int i = 0; i < n; i++){
		for(auto adj_node:adj[i]){
			if(adj_node == par[i])
		}
	}
}