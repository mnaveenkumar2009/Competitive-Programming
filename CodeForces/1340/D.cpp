#include <bits/stdc++.h>
using namespace std;

#define int long long
vector <int> adj[100002];
vector <pair <int, int> > prin;

void dfs(int node, int par, int x, int par_val){
    // cout << node << ' ' << x << '\n';
    prin.push_back({node + 1, x});
    int num_of_chil = adj[node].size() - 1 + (node == 0);
    bool xxx = 0;
    if(x >= num_of_chil + 1 && par_val != 0){
        
        x -= num_of_chil + 1;
        // cout << node << ' ' << x << '\n';
        prin.push_back({node + 1, x});
    }
    for(auto ch:adj[node]){
        if(ch != par){
            dfs(ch, node, x + 1, x);
            x++;
            num_of_chil--;
            if(par_val == num_of_chil){
                prin.push_back({node + 1, 0});
                x = 0;
            }
        }
    }
    if(par != -1){
	    if(x != par_val){
	        prin.push_back({node + 1, par_val});
	    }
        prin.push_back({par + 1, par_val + 1});
    }
}
signed main(){
    int n, u, v;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, 0, -1);
    int Y = prin.size();
    cout << Y << '\n';
    // for(auto i:prin){
    //     cout << i.first << ' ' << i.second << '\n';
    // }
    for(int i = 0; i < Y; i++){
        cout << prin[i].first << ' ' << prin[i].second << '\n';
        // if(i){
            // assert(prin)
        // }
    }
}