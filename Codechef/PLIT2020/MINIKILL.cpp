#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    vector <int> adj[n], C(n, 0);

    for(int i = 0; i < n - 1; i++){
        int u, v;

        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        if(adj[i].size() == 1){
            C[adj[i][0]]++;
        }
    }
    for(auto i:C)
        ans += max(0LL, i - 1);
    cout << ans << '\n';
}