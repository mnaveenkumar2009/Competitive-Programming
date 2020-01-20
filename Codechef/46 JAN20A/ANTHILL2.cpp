#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 512

int n, m, x;
int adj[N][N];
bool M[N][N];

int solve(){
	int A[N][N];
	int adj2[N][N];
	for(int i =0; i < N; i++){
		for(int j = 0; j < N; j++){
			adj2[i][j] = adj[i][j];
		}
	}
	vector <pair <int, int> > edges;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			A[i][j] = M[i][j];
			A[j][i] = M[j][i];
			if(M[i][j]){
				edges.push_back({i, j});
			}
		}
	}
	random_shuffle(edges.begin(), edges.end());
	vector<vector<pair <int, int> > > ans;
	vector<pair <int, int> > X;
	for(auto edge:edges){
		if((adj2[edge.first][edge.second] | adj2[edge.second][edge.first]) > 2)
			continue;
		int no1 = 0, no0 = 0;
		for(auto edge2:X){
			if(edge2.first == edge.first){
				if(adj2[edge2.second][edge.second] == 1)
					no1++;
				if(adj2[edge2.second][edge.second] == 0)
					no0++;
			}
			if(edge2.first == edge.second){
				if(adj2[edge2.second][edge.first] == 1)
					no1++;
				if(adj2[edge2.second][edge.first] == 0)
					no0++;
			}
			if(edge2.second == edge.first){
				if(adj2[edge2.first][edge.second] == 1)
					no1++;
				if(adj2[edge2.first][edge.second] == 0)
					no0++;
			}
			if(edge2.second == edge.second){
				if(adj2[edge2.first][edge.first] == 1)
					no1++;
				if(adj2[edge2.first][edge.first] == 0)
					no0++;
			}
		}
		if(no1 * 5 >= no0){
			for(auto edge2:X){
				if(edge2.first == edge.first){
					adj2[edge2.second][edge.second] |= 2;
				}
				if(edge2.first == edge.second){
					adj2[edge2.second][edge.first] |= 2;
				}
				if(edge2.second == edge.first){
					adj2[edge2.first][edge.second] |= 2;
				}
				if(edge2.second == edge.second){
					adj2[edge2.first][edge.first] |= 2;
				}
			}
			X.push_back(edge);
		}
		else{
			if(X.size())
				ans.push_back(X);
			X.clear();
			X.push_back(edge);			
		}
	}
	if(X.size())
		ans.push_back(X);
	int c = 0;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if((adj2[i][j] | adj2[j][i]) == 2){
				c++;
			}
		}
	}
	cout << c + ans.size() << '\n';
	for(auto vec:ans){
		cout << "1 " << vec.size() << ' ';
		for(auto i:vec)cout << i.first + 1 << ' ' << i.second + 1 << ' ';
		cout << '\n';
	}
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if((adj2[i][j] | adj2[j][i]) == 2){
				cout << "2 " << i + 1 << ' ' << j + 1 << '\n';
			}
		}
	}
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(0));
    cin >> n >> m >> x >> x;
    memset(adj, 0, sizeof(adj));
    memset(M, 0, sizeof(M));
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u-1][v-1] = adj[v-1][u-1] = 1;
    	M[u-1][v-1] = M[v-1][u-1] = 1;
    }
    solve();
    return 0;
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