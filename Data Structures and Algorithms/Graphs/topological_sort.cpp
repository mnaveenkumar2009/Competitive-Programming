#include <bits/stdc++.h>
using namespace std;
#define MAXX 100005
vector <int> adj[MAXX];
bool vis[MAXX];

void dfs(int node, vector <int> &a){
    vis[node]=1;
    for(auto node_adj:adj[node]){
        if(!vis[node_adj]){
            dfs(node_adj, a);
        }
    }
    a.push_back(node);
}
int main(){
    memset(vis, 0, sizeof(vis));
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector <int> ans;
    for(int i = 0; i < n; i++){
        if(!vis[i])
            dfs(i,ans);
    }
    reverse(ans.begin(),ans.end());
    for(auto node:ans)
        cout<<node<<' ';
    cout<<'\n';
}

/*
    Input : 
    6 6
    5 2
    5 0
    4 0
    4 1
    3 1
    2 3

    Output :
    5 4 2 3 1 0
*/