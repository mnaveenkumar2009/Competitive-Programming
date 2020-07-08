#include <bits/stdc++.h>
using namespace std;

#define int long long

vector <int> adj[200005];
int siz[200005], dep[200005];
bool vis[200005];
int dfs(int node, int depth){
	vis[node] = 1;
	dep[node] = depth;
	int ret = 1;
	for(int j:adj[node]){
		if(!vis[j]){
			ret += dfs(j, depth + 1);
		}
	}
	return siz[node] = ret;
}

signed main(){
	memset(vis, 0, sizeof(vis));
    int n, k, u, v, ans = 0;;
    cin >> n >> k;
	for (int i = 0; i < n - 1; i++){
		cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	dfs(0, 1);
	for(int i = 0; i < n; i++){
	    siz[i] -= dep[i];
	}
	sort(siz, siz + n);
	reverse(siz, siz + n);
// 	for(int i = 0; i < n ;i++){
// 	    cout << siz[i] << '\n';
// 	}

	for(int i = 0; i < n - k; i++){
		ans += siz[i];
	}
	cout << ans << '\n';
}