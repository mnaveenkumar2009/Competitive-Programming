#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
vector<int> adj[1000];
bool vis[1000];
int cur_col[1000], exp_col[1000];
int main(){
	memset(vis, 0, sizeof(vis));
	int n, m;
	cin >> n >> m;
	int X, Y, P, Q;
	cin >> X >> Y >> P >> Q;
	string s;
	cin >> s;
	for(int i = 0; i < n; i++){
		if(s[i] == 'R')
			exp_col[i] = cur_col[i] = 0;
		if(s[i] == 'G')
			exp_col[i] = cur_col[i] = 1;
		if(s[i] == 'B')
			exp_col[i] = cur_col[i] = 2;
		int u, v;
		cin >> u >> v;
	}
	for(int i = 0; i < m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		x--;y--;z--;
		adj[x].push_back(y);
		adj[x].push_back(z);
		adj[y].push_back(x);
		adj[y].push_back(z);
		adj[z].push_back(x);
		adj[z].push_back(y);
	}
	// dfs(0, 0);
	int noi = n;
	while(noi--)
		for(int i = 0; i < n; i++){
			int coun[3] = {0, 0, 0};
			for(auto child:adj[i])
				coun[exp_col[child]]++;
			exp_col[i] = min_element(coun, coun + 3) - coun;
		}
	int c[3] = {0, 1, 2}, d[3], min_cost = 1e9;
	do{
		int c_cost = 0;
		for(int i = 0; i < n; i++){
			if(cur_col[i] != c[exp_col[i]])
				c_cost++;
		}
		if(c_cost < min_cost){
			min_cost = c_cost;
			d[0] = c[0];
			d[1] = c[1];
			d[2] = c[2];
		}
	}
	while(next_permutation(c, c+3));
	// for(int i = 0; i < n; i++){
	// 	cout << exp_col[i] << ' ';
	// }
	// cout << '\n';
	min_cost = min(min_cost, P);
	int prin = min_cost;
	vector<pair <int, int> > S;

	for(int i = 0; i < n; i++){
		int coun[3] = {0, 0, 0};
		for(auto child:adj[i]){
			coun[d[exp_col[child]]]++;
		}
		int exp_ans = 1, cur_ans = 1;
		for(int j = 0; j < 3; j++){
			if(j != d[exp_col[i]]){
				exp_ans *= coun[j];
			}
			if(j != cur_col[i]){
				cur_ans *= coun[j];
			}
		}
		S.push_back({exp_ans - cur_ans, i});
	}
	sort(S.begin(), S.end());
	reverse(S.begin(), S.end());

	for(auto it:S){
		auto i = it.second;
		if(min_cost && cur_col[i] != d[exp_col[i]]){
			cur_col[i] = d[exp_col[i]];
			--min_cost;
		}
	}
	char ans[3] = {'R', 'G', 'B'};
	cout << prin << ' ' << 0 << '\n';
	for(int i = 0; i < n; i++){
		cout << ans[cur_col[i]];
	}
	cout <<  '\n';
}
