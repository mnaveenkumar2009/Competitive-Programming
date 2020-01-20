#include <bits/stdc++.h>
using namespace std;

#define int long long
#define N 100006

class segmentTree{
	public:
		int n, h, tree[2 * N], lazy[2 * N], Node_Siz[2 * N];
		segmentTree(int n){
			this.n = n;
			for(int i = n; i < 2 * n; i++){
			    Node_Siz[i] = 1;
			    lazy[i] = tree[i] = 0;
			}
			for(int i = n - 1; i >= 0; i--){
			    Node_Siz[i] = Node_Siz[i<<1] + Node_Siz[i<<1|1];
			    lazy[i] = tree[i] = 0;
			}
			h = sizeof(int) * 8 - __builtin_clz(n);
		}
		void apply(int p, int value) {
		    tree[p] += value * Node_Siz[p];
		    if(p < n) lazy[p] += value;
		}
		void push(int p) {
		    for(int s = h; s > 0; --s) {
		        int i = p >> s;
		        if(lazy[i] != 0) {
		            apply(i<<1, lazy[i]);
		            apply(i<<1|1, lazy[i]);
		            lazy[i] = 0;
		        }
		    }
		}
		void modify(int l, int r, int value) {
		    l += n, r += n;
		    int l0 = l, r0 = r - 1;
		    for (; l < r; l >>= 1, r >>= 1) {
		        if (l&1) apply(l++, value);
		        if (r&1) apply(--r, value);
		    }
		    while (l0 > 1) l0 >>= 1, tree[l0] = (tree[l0<<1] + tree[l0<<1|1]) + lazy[l0] * Node_Siz[l0];
		    while (r0 > 1) r0 >>= 1, tree[r0] = (tree[r0<<1] + tree[r0<<1|1]) + lazy[r0] * Node_Siz[r0];
		}
		int query(int l, int r) {
		    l += n, r += n;
		    push(l);
		    push(r - 1);
		    int res = 0;
		    for (; l < r; l >>= 1, r >>= 1) {
		        if (l&1) res += tree[l++];
		        if (r&1) res += tree[--r];
		    }
		    return res;
		}		
};

class HLD{
	private:
		segmentTree STree;
		int par[N], sz[N], root[N], indx[N], cnt = -1, n;

		HLD(int n){
			this.n = n;
			STree.segmentTree(n);
		}

		bool check(int u, int v){
			return sz[u] > sz[v];
		}
		
		int dfs(int node, int p){
			sz[node] = 1;
			par[node] = p;
			for(auto child: adj[node]){
				if(child != p)
					sz[node] += dfs(child, node);
			}
			return sz[node];
		}

		void set_indices(int node, int par){
			++cnt;
			if(indx[par] != cnt - 1 || par == -1)
				root[node] = node;
			else
				root[node] = root[par];
			sort(adj[node].begin(), adj[node].end(), check);
			for(auto child:adj[node]){
				set_indices(child, node);
			}
		}
	public:
		void init(){
			dfs(0, -1);
			set_indices(0, -1);
		}
		int query(int l, int r){
			int res = 0;
			while(root[l] != root[r]){
				if(l > r){
					res += STree.query(indx[], l + 1);
					l = par[root[l]];
				}
				else{
					res += STree.query();
					r = par[root[r]];
				}
			}
			return res;
		}
};

signed main(){
	int n;
	cin >> n;
	HLD G(n);
	for(int i = 0; i < n - 1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	string s;
	while(cin >> s){
		if(s == "QUERY"){
			cout << 
		}
		if(s == "CHANGE"){

		}
	}
}