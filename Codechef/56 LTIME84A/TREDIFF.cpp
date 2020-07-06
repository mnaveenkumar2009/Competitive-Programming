#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, l;
vector<vector<int>> adj;

int A[200005];

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
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
        for(int i = 0; i < n; i++){
            cin >> A[i];
        }
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        preprocess(0);
        // for(int i = 0; i < n; i++){
        //     cout << up[i][0] << ' ';
        // }cout << '\n';

        while(q--){
            int x, y;
            cin >> x >> y;
            x--; y--;
            int lc = lca(x, y);
            // cout << x << ' ' << y << ' ' << lc << '\n';
            vector <bool> X(101, 0);
            int prev = -1;
            int ans = 500;
            X[A[lc]] = 1;
            while(x != lc){
                // cout << x << ' ' << ans << '\n';
                if(X[A[x]]){ans = 0;break;}
                X[A[x]] = 1;
                x = up[x][0];
            }
            while(ans && y != lc){
                // cout << "y " << y << ' ' << up[y][0] << ' ' << ans << '\n';
                if(X[A[y]]){ans = 0;break;}
                X[A[y]] = 1;
                y = up[y][0];
            }
            if(ans){
                for(int i = 1; i < 101; i++){
                    if(X[i]){
                        if(prev != -1){
                            ans = min(ans, i - prev);
                        }
                        prev = i;
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}