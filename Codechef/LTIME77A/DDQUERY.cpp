#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
int D[1004][1004];
bool vis[2000];
vector <int> adj[1005];
int orig = 0;
void dfs(int node, int dist){
    D[orig][node] = D[node][orig] = dist;
    vis[node] = 1;
    for(auto child:adj[node]){
        if(!vis[child]){
            dfs(child, dist + 1);
        }
    }
}
signed main(){
    int t;
    cin >> t;    
    while(t--){
        int n, q;
        cin >> n >> q;
        for(int i = 0; i < n; i++){
            vis[i] = 0;
            adj[i].clear();
        }
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                vis[j] = 0;
            }
            orig = i;
            dfs(i, 0);
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout<<D[i][j] << ' ';
        //     }cout<<'\n';
        // }
        while(q--){
            int a, b, da, db;
            cin >> a >> da >> b >> db;
            a--;
            b--;
            bool we = 1;
            for(int i = 0; i < n; i++){
                if(D[i][a] == da && D[i][b] == db){
                    cout  << i + 1 << '\n';
                    we = 0;
                    break;
                }
            }
            if(we){
                cout << "-1\n";
            }        
        }
    }
}