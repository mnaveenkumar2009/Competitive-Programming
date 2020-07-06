#include <bits/stdc++.h>
using namespace std;

// lca : https://cp-algorithms.com/graph/lca_binary_lifting.html
int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout, depth;
vector<vector<int>> up;

void dfs(int v, int p, int d)
{
	// cout << v <<' '<< p<< ' ' <<  d <<'\n';
	depth[v] = d;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, d + 1);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    depth.resize(n);
    up.resize(n, vector<int>(l + 1));
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root, 0);
}
int dist(int u, int v){
	int x = lca(u, v);
	return depth[u] - depth[x] + depth[v] - depth[x];
}
int main(){
	cin >> n;
	adj.resize(n);
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}

	preprocess(0);
	int q;
	cin >> q;
	while(q--){
		int x, a, b, y, k;
		cin >> x >> y >> a >> b >> k;
		x--;y--;a--;b--;

		int d1 = dist(a, b), d2 = dist(a,x) + dist(b,y) + 1, d3 = dist(a, y) + dist(b, x) + 1;
		string ans = "NO";
		if(d1 <= k && ((d1%2) == (k % 2)))
			ans = "YES";
		if(d2 <= k && ((d2%2) == (k % 2)))
			ans = "YES";
		if(d3 <= k && ((d3%2) == (k % 2)))
			ans = "YES";
		cout << ans << '\n';
	}
}