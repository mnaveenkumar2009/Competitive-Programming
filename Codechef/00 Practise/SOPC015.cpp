#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	bool isp[2000006];
	memset(isp, 1, sizeof(isp));
	isp[0] = isp[1] = 0;
	for(int i = 2; i < 2e6; i++){
		if(isp[i]){
			for(int j = 2; i * j < 2e6; i++){
				isp[i * j] = 0;
			}
		}
	}
	int n;
	cin >> n;
	set <int> adj[n];
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u-1].insert(v-1);
		adj[v-1].insert(u-1);
	}
	vector <int> leaves;
	for(int i = 0; i < n; i++){
		if(adj[i].size() == 1){
			leaves.push_back(i);
		}
	}
	int k = 0;
	while(leaves.size()){
		if(leaves.size() == 1 && adj[leaves[0]].size() == 0)
			break;
		map <int, int> m;
		int c = 0;
		for(auto i : leaves){
			// cout << i << ' ';
			m[*adj[i].begin()]++;
		}
		// cout << '\n';
		set <int> S;
		for(auto i : m){
			c++;
			S.insert(i.second);
			if(!isp[i.second]){
				cout << "NO\n";
				return 0;
			}
		}
		if(S.size() != c){
			cout << "NO\n";
			return 0;			
		}

		vector <int> newl;
		for(auto i: leaves){
			int par = *adj[i].begin();
			adj[par].erase(i);
			if(adj[par].size() == 1)
				newl.push_back(par);
		}
		k++;
		leaves = newl;
	}
	cout << "YES\n" << k << '\n';
}