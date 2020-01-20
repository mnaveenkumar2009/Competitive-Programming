#include <bits/stdc++.h>
using namespace std;

#define N 100006
int sz[N], maxi[N], par[N], n;
vector <int> adj[N];
int dfs(int node, int p){
	par[node] = p;
	sz[node] = 1;
	for(auto child:adj[node]){
		if(child != p)
			sz[node] += dfs(child, node);
	}
	maxi[node] = n - sz[node];
	return sz[node];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++)
			adj[i].clear();
		for(int i = 0; i < n - 1; i++){
			int u, v;
			cin >> u >> v;
			adj[u - 1].push_back(v - 1);
			adj[v - 1].push_back(u - 1);
		}
		dfs(0, -1);
		char s[n+5];
		s[n] = '\0';
		for(int i = 0; i < n; i++){
			for(auto child:adj[i])
				if(child != par[i])
					maxi[i] = max(maxi[i], sz[child]);
			if(maxi[i] > n - maxi[i])
				s[i] = '0';
			else
				s[i] = ('1' - (n&1));
		}
		cout << s << '\n';
	}
}