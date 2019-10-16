#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100001
#define mod 1000000007
vector <int> adj[N];
unordered_map <int, int> A[N];
bool vis[N];
int X[N];
int ans = 0;
void dfs(int node, int par){
    vis[node] = 1;
    if(par != -1)
        for(auto G : A[par])
            A[node][__gcd(G.first, X[node])] += G.second;
    A[node][X[node]] += 1;
    for(auto child: adj[node])
        if(!vis[child])
            dfs(child, node);
    for(auto G : A[node])
        ans = (ans + G.first * G.second) % mod;
}
signed main(){
    int n, u, v;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> X[i];
    while(cin >> u >> v){
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    dfs(0, -1);
    cout << ans << '\n';
}