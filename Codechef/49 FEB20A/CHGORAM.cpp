#include <bits/stdc++.h>
using namespace std;
#define int long long

long long tripsum(vector <int> &a){
	int n = a.size();
	if(n <= 2)return 0;
	long long ans = 0, sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
	}
	ans = sum * sum * sum;
	for(int i = 0; i < n; i++){
		ans -= a[i] * a[i] * a[i];
		ans -= a[i] * a[i] * 3 * (sum - a[i]);
	}
	return ans / 6;
}

bool S[200005];
int depth[200005], pos[200005];
long long Tans = 0, n;
vector<bool> dead;
vector< vector<int> > g;

// https://codeforces.com/blog/entry/57593
int Centroid(int root) {
    static vector<int> sz(g.size());
    function<void (int, int)> get_sz = [&](int u, int prev) {
        sz[u] = 1;
        for (auto v : g[u]) if (v != prev && !dead[v]) {
            get_sz(v, u);
            sz[u] += sz[v];
        }
    };
    get_sz(root, -1);
    int n = sz[root];
    function<int (int, int)> dfs = [&](int u, int prev) {
        for (auto v : g[u]) if (v != prev && !dead[v]) {
            if (sz[v] > n / 2) {
                return dfs(v, u);
            }
        }
        return u;
    };
    return dfs(root, -1);
}

vector <int> dist_temp;
vector<pair <int, int> > depths_order;

void dfs1(int x, int p, int depth){
	if(S[x])
		dist_temp.push_back(depth);
	for(auto v:g[x]){
		if(!dead[v] && v != p){
			dfs1(v, x, depth + 1);
		}
	}
}
void dfs2(int x, int p, int dept){
	depths_order.push_back({dept, x});
	depth[x] = dept;
	for(auto v:g[x]){
		if(!dead[v] && v != p){
			dfs2(v, x, dept + 1);
		}
	}
}

void solve(int c){
	dead[c] = 1;
	vector <vector <int> > dist(n + 1);
	dist[0].push_back(S[c]);
	for(auto d:g[c]){
		if(!dead[d]){
			dist_temp.clear();
			dfs1(d, c, 1);
			if(!(int)(dist_temp.size()))continue;
			vector <int> A(*max_element(dist_temp.begin(), dist_temp.end()), 0);
			for(auto i:dist_temp)
				A[i-1]++;
			int N = A.size();
			for(int i = 0; i < N; i++){
				if(A[i])
					dist[i + 1].push_back(A[i]);
			}
		}
	}
	for(int i = 0; i < n; i++)
		Tans += tripsum(dist[i]);
	
	vector <int> distsum(n + 1);
	for(int i = 0; i < n + 1; i++){
		distsum[i] = 0;
		for(auto j:dist[i])
			distsum[i] += j;
	}
	// for(auto d:g[c]){
	// 	if(!dead[d]){
	// 		// cout << d << ' ' << Tans<<'\n';
	// 		depths_order.clear();
	// 		dist_temp.clear();
	// 		dfs1(d, c, 1);
	// 		vector <int> A((*max_element(dist_temp.begin(), dist_temp.end())) + 1, 0);
	// 		for(auto i:dist_temp)
	// 			A[i]++;
	// 		int N = A.size();
	// 		for(int i = 0; i < N; i++){
	// 			A[i] = distsum[i] - A[i];
	// 		}
	// 		dfs2(d, c, 1);
	// 		sort(depths_order.begin(), depths_order.end());
	// 		reverse(depths_order.begin(), depths_order.end());

	// 		int TS = depths_order.size();
	// 		vector <vector <int> > Car(TS);

	// 		for(int i = 0; i < TS; i++)
	// 			pos[depths_order[i].second] = i;

	// 		for(auto nod:depths_order){
	// 			int node = nod.second, larg_vec = 0, larg_vec_pos = -1, seclarg_vec = 0, seclarg_vec_pos = -1;
	// 			for(auto v:g[node]){
	// 				if(!dead[v] && depth[v] > depth[node]){
	// 					if(Car[pos[v]].size() > larg_vec){
	// 						larg_vec_pos = pos[v];
	// 						larg_vec = Car[pos[v]].size();
	// 					}
	// 				}
	// 			}
	// 			if(larg_vec == 0){
	// 				Car[pos[node]].push_back(S[node]);
	// 			}
	// 			else{
	// 				for(auto v:g[node]){
	// 					if(!dead[v] && depth[v] > depth[node] && pos[v] != larg_vec_pos){
	// 						if(Car[pos[v]].size() > seclarg_vec){
	// 							seclarg_vec_pos = pos[v];
	// 							seclarg_vec = Car[pos[v]].size();
	// 						}
	// 					}
	// 				}
	// 				if(seclarg_vec){
	// 					vector <int> D(seclarg_vec, 0), F(seclarg_vec, 0);
	// 					for(auto v:g[node]){
	// 						if(!dead[v] && depth[v] > depth[node]){
	// 							int j = Car[pos[v]].size(), NN = j;
	// 							for(auto i:Car[pos[v]]){
	// 								D[NN - j] += i;
	// 								F[NN - j] -= i * i;
	// 								j--;
	// 							}
	// 						}
	// 					}
	// 					for(int i = 0; i < seclarg_vec; i++){
	// 						D[i] *= D[i];
	// 						D[i] += F[i];
	// 						D[i] /= 2;
	// 						int req_depth = (i + 1) - nod.first;
	// 						if(req_depth >= 0){
	// 							// cout << d << ' ' << i <<' ' << nod.first << '\n';
	// 							Tans += D[i] * A[req_depth];
	// 						}
	// 					}
	// 				}
	// 				swap(Car[pos[node]], Car[larg_vec_pos]);
	// 				Car[pos[node]].push_back(S[node]);
	// 				for(auto v:g[node]){
	// 					if(!dead[v] && depth[v] > depth[node] && pos[v] != larg_vec_pos){
	// 						int NN = Car[pos[node]].size(), j = Car[pos[v]].size() + 1;
	// 						for(auto i:Car[pos[v]]){
	// 							Car[pos[node]][NN - j] += i;
	// 							j--;
	// 						}
	// 					}
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	for(auto d: g[c]){
		if(!dead[d]){
			solve(Centroid(d));
		}
	}
}
signed main(){
	int t;
	cin >> t;
	while(t--){
		Tans = 0;
		cin >> n;
		g.clear();
		g.resize(n);
		dead.clear();
		dead.resize(n, 0);
		for(int i = 0; i < n - 1; i++){
			int u, v;
			cin >> u >> v;
			g[u - 1].push_back(v - 1);
			g[v - 1].push_back(u - 1);
		}
		for(int i = 0; i < n; i++)
			cin >> S[i];
		// cout << Centroid(0) << '\n';
		solve(Centroid(0));
		cout << Tans*6 << '\n';
	}
}