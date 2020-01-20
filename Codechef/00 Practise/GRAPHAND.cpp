#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, s, t;
vector< pair <int, pair <int, int> > > adj[100006];

int f(int k){
    multiset  < pair <long long, int> > S;
    S.insert({0, s});
    vector <long long> dis(n, 1e18);
    vector <bool> vis(n, 0);
    dis[s] = 0;
    while(S.size()){
        pair <long long, int> cur_node = *S.begin();
        S.erase(S.begin());
        
        int x = cur_node.second;
        long long weight = cur_node.first;
        
        if(vis[x])
            continue;
        
        for(auto adj_node: adj[x]){
            if(dis[adj_node.first] > weight + adj_node.second.second && ((adj_node.second.first&k) == k)){
                dis[adj_node.first] = weight + adj_node.second.second;
                S.insert({dis[adj_node.first], adj_node.first});
            }
        }
    }
    return dis[t];
}
signed main(){
	int k, ans = 1e18;
	cin >> n >> m;
	while(m--){
		int u, v, cost, val;
		cin >> u >> v >> cost >> val;
		adj[u-1].push_back({v-1, {val, cost}});
		adj[v-1].push_back({u-1, {val, cost}});
	}
	cin >> s >> t >> k;
	s--;
	t--;
	for(int bit = 32; bit >= 0; bit--){
		if(k & (1LL<<bit))
			continue;
		ans = min(ans, f(k + (1LL<<bit) - (k&((1LL<<bit) - 1))));
	}

	ans = min(ans, f(k));
	if(ans == 1e18)
		ans = -1;
	cout << ans << '\n';
}