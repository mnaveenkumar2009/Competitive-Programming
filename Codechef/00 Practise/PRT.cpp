#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int val[300006], par[300006];
vector <int> adj[300006];

int dfs(int node, int p){
    par[node] = p;
    if(val[node] != -1)
        return val[node];
    int ret = 0;
    for(auto child: adj[node]){
        if(child != p)
            ret += dfs(child, node);
    }
    return val[node] = ret;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            val[i] = -1;
            par[i] = -1;
            adj[i].clear();
        }
        sort(a, a + n);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        if(n == 1){
            cout << "0\n";
            continue;
        }
        if(n == 2){
            cout << ((a[0] + a[1]) % mod) << '\n';
            continue;
        }
        int root = 0, no_of_leaves = 0;
        for(int i = 0; i < n; i++){
            if(adj[i].size() == 1){
                val[i] = 1;
                no_of_leaves++;
            }
            else
                root = i;
        }
        dfs(root, -1);
        vector <int> v;
        for(int i = 0; i < n; i++){
            int cur = 0;
            for(auto child:adj[i]){
                if(child != par[i])
                    cur += (no_of_leaves - val[child]) * val[child];
                else
                    cur += (no_of_leaves - val[i]) * val[i];
            }
            if(adj[i].size() == 1)
                cur *= 2;
            v.push_back(cur);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++){
            v[i] %= mod;
            ans = (ans + v[i] * a[i]) % mod;
        }
        cout << ((ans * 500000004) % mod) << '\n';
    }
}