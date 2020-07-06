#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double

vector <int> ans;
vector <int> cur;
vector <int> adj[200005];
bool vis[200005];
void dfs(int node){
    vis[node] = 1;
    cur.push_back(node);
    for(int child:adj[node]){
        if(!vis[child])
            dfs(child);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ans.clear();
        int n, m, u, v;
        cin >> n >> m;
        int num[n], den[n];
        ld Ratio[n];
        for(int i = 0; i < n; i++){
            vis[i] = 0;
            adj[i].clear();
            cin >> num[i];
        }
        for(int i = 0; i < n; i++){
            cin >> den[i];
            Ratio[i] = num[i];
            Ratio[i] /= (ld)den[i];
        }
        int pos = max_element(Ratio, Ratio + n) - Ratio;
        bool keep[n];
        memset(keep, 0, sizeof(keep));
        for(int i = 0; i < n; i++){
            if(num[pos] * den[i] == num[i] * den[pos])
                keep[i] = 1;
            // cout << keep[i];
        }
        // cout << '\n';
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            if(keep[u-1] && keep[v-1]){
                adj[u-1].push_back(v-1);
                adj[v-1].push_back(u-1);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i] && keep[i]){
                cur.clear();
                dfs(i);
                if(cur.size() > ans.size()){
                    ans = cur;
                }
            }
        }
        cout << ans.size() << '\n';
        for(auto i:ans) cout << i + 1 << ' ';cout << '\n';
    }
}