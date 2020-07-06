#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, l;
vector<vector<int>> adj;

int A[100005], INC[100005], DEC[100005], DEPT[100005];

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    if(v != p)
        DEPT[v] = DEPT[p] + 1;
    INC[v] = DEC[v] = 0;
    if(A[v] > A[p]){
        DEC[v] = DEC[p] + 1;
    }
    if(A[v] < A[p]){
        INC[v] = INC[p] + 1;
    }
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
int ances(int v, int x){
    for (int i = l; i >= 0; --i) {
        if (x >= (1LL << i)){
            v = up[v][i];
            x -= (1LL << i);
        }
    }
    return v;
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    DEPT[root] = 0;
    dfs(root, root);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        adj.clear();
        int q;
        cin >> n >> q;
        adj.resize(n);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        preprocess(0);

        // for(int i = 0; i < n; i++){
        // //     cout << DEPT[i] << ' ' << INC[i] << ' ' << DEC[i] << '\n';
        //     for(int j = 0; j <= DEPT[i]; j++){
        //         cout << ances(i, j) << ' ';
        //     }cout << '\n';
        // }
        while(q--){
            int x, y;
            cin >> x >> y;
            x--; y--;
            int lc = lca(x, y);
            bool we = 0;
            if(DEPT[x] - INC[x] > DEPT[lc]){
                if(DEPT[y] - INC[y] <= DEPT[lc]){
                    x = ances(x, INC[x]);
                    if(DEPT[x] - DEC[x] <= DEPT[lc]){
                        we = 1;
                    }
                }
            }
            else{
                if(DEPT[y] - INC[y] > DEPT[lc]){
                    y = ances(y, INC[y]);
                    if(DEPT[y] - DEC[y] <= DEPT[lc]){
                        we = 1;
                    }

                }
                else{
                    we = 1;
                }
            }
            cout << we;
            // cout << '\n';
        }
        cout << '\n';
    }
}