// https://codeforces.com/blog/entry/43230
// https://ideone.com/6NVoPD
#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007 
#define int long long

int pr(int x, int y){
    x %= mod;
    int res = 1;
    while(y){
        if(y&1){
            res =( res * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return res;
}
const int MAXN = 100005;
const int MAXM = 100005;
const int LN = 23;

int INV[2300006];
 
int N, M, cur, A[MAXN], LVL[MAXN], DP[LN][MAXN];
vector <int> prf[MAXN];
int BL[MAXN << 1], ID[MAXN << 1], VAL[1000006], ANS[MAXM];
int l[MAXN], r[MAXN];
bool VIS[MAXN];
vector < int > adjList[MAXN];
 
struct query{
	int id, l, r, lc;
	bool operator < (const query& rhs){
		return (BL[l] == BL[rhs.l]) ? (r < rhs.r) : (BL[l] < BL[rhs.l]);
	}
}Q[MAXM];
 
// Set up Stuff
void dfs(int u, int par){
	l[u] = ++cur; 
	ID[cur] = u;
	for (int i = 1; i < LN; i++) DP[i][u] = DP[i - 1][DP[i - 1][u]];
	for (int i = 0; i < adjList[u].size(); i++){
		int v = adjList[u][i];
		if (v == par) continue;
		LVL[v] = LVL[u] + 1;
		DP[0][v] = u;
		dfs(v, u);
	}
	r[u] = ++cur; ID[cur] = u;
}
 
// Function returns lca of (u) and (v)
inline int lca(int u, int v){
	if (LVL[u] > LVL[v]) swap(u, v);
	for (int i = LN - 1; i >= 0; i--)
		if (LVL[v] - (1 << i) >= LVL[u]) v = DP[i][v];
	if (u == v) return u;
	for (int i = LN - 1; i >= 0; i--){
		if (DP[i][u] != DP[i][v]){
			u = DP[i][u];
			v = DP[i][v];
		}
	}
	return DP[0][u];
}
 
inline void check(int x, int& res){
	// If (x) occurs twice, then don't consider it's value 
// 	if ( (VIS[x]) and (--VAL[A[x]] == 0) ) res--; 
// 	else if ( (!VIS[x]) and (VAL[A[x]]++ == 0) ) res++;
    // cout << x << ' ' << VIS[x] << ' ' << res << '\n';
	if(VIS[x]){
	    for(auto d:prf[x]){
	        VAL[d]--;
	        res *= ((VAL[d] + 1) * (INV[VAL[d] + 2])) % mod;
	        res %= mod;
	    }
	}
	else{
	    for(auto d:prf[x]){
	        VAL[d]++;
	       // cout << d << ' ' << VAL[d] << ' ' << INV[VAL[d]] << '\n';
	        res *= ((VAL[d] + 1) * INV[VAL[d]]) % mod;
	        res %= mod;
	    }
	}
	VIS[x] ^= 1;
}
 
void compute(){
 
	// Perform standard Mo's Algorithm
	int curL = Q[0].l, curR = Q[0].l - 1, res = 1;
 
	for (int i = 0; i < M; i++){
	    
		while (curL < Q[i].l) check(ID[curL++], res);
		while (curL > Q[i].l) check(ID[--curL], res);
		while (curR < Q[i].r) check(ID[++curR], res);
		while (curR > Q[i].r) check(ID[curR--], res);
 
		int u = ID[curL], v = ID[curR];
 
		// Case 2
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
 
		ANS[Q[i].id] = res;
 
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
	}
 
	for (int i = 0; i < M; i++) printf("%d\n", ANS[i]);
}
 
signed main(){
    for(int i = 1; i <= 2300005; i++){
        INV[i] = pr(i, mod - 2);
    }
	int u, v, x;
    int t;
    cin >> t;
	while (t--){
        scanf("%d", &N);
		// Cleanup
		cur = 0;
		memset(VIS, 0, sizeof(VIS));
		memset(VAL, 0, sizeof(VAL));
		for (int i = 1; i <= N; i++) adjList[i].clear();
		if(N <= 1e3)
		    for (int i = 1; i <= N; i++) prf[i].clear();
 
		// Inputting Tree
		for (int i = 1; i < N; i++){
			scanf("%d %d", &u, &v);
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
 
		// Inputting Values
		for (int i = 1; i <= N; i++){ 
		    scanf("%d", &A[i]);
		    int XX = sqrt(A[i]);
		    for(int j = 2; j <= XX; j++){
		        while(A[i] % j == 0){
		            prf[i].push_back(j);
		            A[i] /= j;
		        }
		    }
		    if(A[i] != 1){
		        prf[i].push_back(A[i]);
		    }
		}
    
		// Preprocess
		DP[0][1] = 1;
		dfs(1, -1);
		int siz = sqrt(cur);
		assert(siz);
 
		for (int i = 1; i <= cur; i++) BL[i] = (i - 1) / siz + 1;
 
        scanf("%d", &M);
		for (int i = 0; i < M; i++){
			scanf("%d %d", &u, &v);
			Q[i].lc = lca(u, v);
			if (l[u] > l[v]) swap(u, v);
			if (Q[i].lc == u) Q[i].l = l[u], Q[i].r = l[v];
			else Q[i].l = r[u], Q[i].r = l[v];
			Q[i].id = i;
		}
 
		sort(Q, Q + M);
		compute();
	}
}