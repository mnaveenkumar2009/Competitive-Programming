#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> adj[100003];
int S[10003];

int dfs(int node, int par){
    S[node] = 1;
    for(auto child : adj[node]){
        if(child != par)
            S[node] += dfs(child, node);
    }
    return S[node];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x, u, v;
        cin >> n >> x;
        for(int i = 0; i < n; i++){
            adj[i].clear();
            S[i] = 0;
        }
        for(int i = 0; i < n - 1; i++){
            cin >> u >> v;
            adj[u-1].push_back(v - 1);
            adj[v-1].push_back(u - 1);
        }
        if(adj[x-1].size() <= 1){
            cout << "Ayush\n";
            continue;
        }
        dfs(x - 1, -1);
        int c = -1;
        for(auto i:adj[x - 1]){
            c += (S[i]);
        }
        if(c % 2){
            cout << "Ashish\n";
        }
        else{
            cout << "Ayush\n";
        }
    }
}