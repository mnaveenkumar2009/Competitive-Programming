#include <bits/stdc++.h>
using namespace std;
#define MAXX 100005
vector <pair <int, int> > adj[MAXX];
bool vis[MAXX];

int main(){
    int n, m;
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    multiset  < pair <long long, int> > s;
    s.insert({0, 0});
    vector <long long> dis(n,1e15);
    dis[0]=0;
    while(s.size()){
        pair <long long, int> cur_node=*s.begin();
        s.erase(s.begin());
        
        int x= cur_node.second;
        long long weight = cur_node.first;
        
        if(vis[x])
            continue;
        
        for(auto adj_node:adj[x]){
            if(dis[adj_node.first] > weight + adj_node.second){
                dis[adj_node.first] = weight + adj_node.second;
                s.insert({dis[adj_node.first],adj_node.first});
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout<<dis[i]<<' ';
    }
    cout<<'\n';
}