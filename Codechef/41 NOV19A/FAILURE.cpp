#include <bits/stdc++.h>
using namespace std;
#define MAXN 100004
set <int> back_nodes;
bool vis[MAXN];
set <int> adj[MAXN];
void dfs(int u, int par){
	vis[u] = 1;
	vector <int> v;
	for(auto child:adj[u])
		if(!vis[child])
			v.push_back(child);
		else
			if(child != par)
				back_nodes.insert(child);
	for(auto child: v)
		if(!vis[child])
			dfs(child, u);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			adj[i].clear();
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			adj[u-1].insert(v-1);
			adj[v-1].insert(u-1);
		}
		set < pair <int, int> > v;
		for(int i = 0; i < n; i++)
			if(adj[i].size())
				v.insert({adj[i].size(), i});
		while(v.size()){
			auto X = *v.begin();
			if(X.first == 1){
				int adj_node = (*adj[X.second].begin());
				adj[adj_node].erase(X.second);
				adj[X.second].clear();
				v.erase(X);
				v.erase({adj[adj_node].size() + 1, adj_node});
				if(adj[adj_node].size())
					v.insert({adj[adj_node].size(), adj_node});
			}
			else
				break;
		}
		int maxdeg = -1, min_node;
		for(int i = 0; i < n; i++){
			if(maxdeg < (int)(adj[i].size())){
				maxdeg = adj[i].size();
				min_node = i;
			}
		}
		back_nodes.clear();
		memset(vis, 0, sizeof(vis));
		dfs(min_node, -1);
		for(int i = 0; i < n; i++)
			if(!vis[i])
				dfs(i, -1);
		if(back_nodes.size() == 1)
			cout << min_node + 1 << '\n';
		else
			cout << "-1\n";
	}
}