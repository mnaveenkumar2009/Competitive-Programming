#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> adj[1000];
	vector <int> cur_col(1000), exp_col(1000);
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
	int change_col = 0;
	while(change_col < P){
		pair <int, int> best = {-1, 0};
		int best_gain = 0;
		for(int i = 0; i < n; i++){
			int coun[3] = {0, 0, 0};
			for(auto child:adj[i]){
				coun[cur_col[child]]++;
			}
			double cur_ans[3] = {coun[1] * coun[2] - 0.001*coun[0], coun[0] * coun[2] - 0.001*coun[1], coun[1] * coun[0] - 0.001*coun[2]};
			if((*max_element(cur_ans, cur_ans + 3)) - cur_ans[cur_col[i]] > best_gain){
				best_gain = (*max_element(cur_ans, cur_ans + 3)) - cur_ans[cur_col[i]];
				best.first = i;
				best.second = max_element(cur_ans, cur_ans + 3) - cur_ans;
			}
		}
		if(best.first == -1)
			break;
		cur_col[best.first] = best.second;
		change_col++;
	}
	swap(exp_col, cur_col);
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

	min_cost = min(min_cost, P);
	int prin = min_cost;
	for(int i = 0; i < n; i++){
		if(min_cost && cur_col[i] != d[exp_col[i]]){
			exp_col[i] = d[exp_col[i]];
			--min_cost;
		}
		else{
			exp_col[i] = cur_col[i];
		}
	}
	char ans[3] = {'R', 'G', 'B'};
	cout << prin << ' ' << 0 << '\n';
	for(int i = 0; i < n; i++){
		cout << ans[exp_col[i]];
	}
	cout <<  '\n';
}
