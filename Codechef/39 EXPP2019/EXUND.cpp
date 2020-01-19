#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, ans = 0;
        cin >> n >> k;
        set <int> adj[n];
        vector <int> leaves;
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            u--;v--;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        for(int i = 0; i < n; i++){
            if(adj[i].size() == 1 && i){
                leaves.push_back(i);
            }
        }
        while(k--){
            vector <int> newleaves;
            if(leaves.size())
                ans += leaves.size();
            else{
                ans = n;
                break;
            }
            for(auto node : leaves){
                int X = *adj[node].begin();
                adj[X].erase(node);
                if(adj[X].size() == 1 && X)
                    newleaves.push_back(X);
                adj[node].clear();
            }
            leaves = newleaves;
        }
        cout << ans << '\n';
    }
}