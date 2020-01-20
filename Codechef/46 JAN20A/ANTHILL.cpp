#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    int n, m, x;
    cin >> n >> m >> x >> x;
    int adj[n][n];
    memset(adj, 0, sizeof(adj));
    map <int, bool> M[n];
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u-1][v-1] = adj[v-1][u-1] = 1;
    	M[u-1][v-1] = M[v-1][u-1] = 1;
    }
    vector <pair <int, vector <int> > > ans;
    for(int i = 0; i < n; i++){
    	vector<int> v;
    	do{
    		v.clear();
    		std::vector<int> vv;
	    	for(int j = i + 1; j < n; j++){
	    		if(adj[i][j] == 1){
	    			vv.push_back(j);
	    		}
	    	}
	    	random_shuffle(vv.begin(), vv.end());
	    	for(int j:vv){
	    		if(adj[i][j] == 1){
	    			int no0 = 0, no1 = 0;
	    			for(auto u:v){
	    				if(adj[u][j] == 1){
	    					no1++;
	    				}
	    				if(adj[u][j] == 0){
	    					no0++;
	    				}
	    			}
	    			if(no1*5 >= no0){
	    				v.push_back(j);
	    			}
	    		}
	    	}
	    	// for(auto j:v)cout << j << ' ';
	    	for(auto j:v){
	    		adj[i][j] |= 2;
	    		for(auto u:v){
	    			adj[u][j] |= 2;
	    			adj[j][u] |= 2;
	    		}
	    	}
	    	if(v.size())
	    		ans.push_back({i, v});
    	}while(v.size());
    }
    int c = ans.size();
    int cur_cost = 0;
    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n; j++){
    		if(adj[i][j] == 2){
    			c++;
    			cur_cost += 2;
    		}
    	}
    }
    for(auto i:ans){
    	cur_cost += 10 * (i.second).size();
    }
    // cout << cur_cost << '\n';
    if(cur_cost <= 10 * (n - 1) + (n*(n-1) - m)){
    	cout << c << '\n';
	    for(auto vv:ans){
	    	auto v = vv.second;
	    	cout << "1 " << v.size() << ' '; 
	    	for(auto i:v)cout << vv.first + 1 << ' ' << i + 1 << ' ';cout << '\n';
	    }
	    for(int i = 0; i < n; i++){
	    	for(int j = i + 1; j < n; j++){
	    		if(adj[i][j] == 2){
	    			cout << "2 " << i + 1 << ' ' << j + 1 << '\n';
	    		}
	    	}
	    }
	}
	else{
		cout << 1 + (n * (n-1))/2 - m << '\n';
		cout << "1 " << n - 1 << ' ';
		for(int i = 1; i < n; i++)
			cout << "1 " << i + 1 << ' ';
		cout << '\n';
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				if(!M[i][j]){
					cout << "2 " << i + 1 << ' ' << j + 1 << '\n';
				}
			}
		}
	}
}