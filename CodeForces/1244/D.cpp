#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define int long long
bool we = 1;
vector <int> adj[MAXN];
int C[3][MAXN];
bool vis[MAXN];
int col[MAXN];
void dfs(int node, int color){
    col[node] = color;
    vis[node] = 1;
    for(auto child:adj[node]){
        if(!vis[child]){
            dfs(child, (color + 1)%3);
        }
    }
}
signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        vis[i] = 0;
        cin >> C[0][i];
    }
    for(int i = 0; i < n; i++){
        cin >> C[1][i];
    }
    for(int i = 0; i < n; i++){
        cin >> C[2][i];
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    for(int i = 0; i < n; i++){
        if(adj[i].size() == 1){
            dfs(i, 0);
            break;
        }
    }
    for(int i = 0; i < n; i++){
        if(adj[i].size() >= 3){
            we = 0;
            break;
        }
    }
    if(!we){
        cout << "-1\n";
        return 0;
    }
    int min_cost = 1e17;
    vector < int> ans(3), fans;
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    fans = ans;
    do{
        int cost = 0;
        for(int i = 0; i < n; i++){
            cost += C[ans[col[i]]][i];
        }
        if(cost < min_cost){
            min_cost = cost;
            fans = ans;
        }
    }while(next_permutation(ans.begin(), ans.end()));
    cout << min_cost << '\n';
    for(int i = 0; i < n; i++){
        cout << fans[col[i]] + 1 << ' ';
    }
    cout << '\n';
}