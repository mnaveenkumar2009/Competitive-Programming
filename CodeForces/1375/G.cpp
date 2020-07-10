#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, u, v;
    cin >> n;
    int col[n] = {0};
    bool vis[n] = {0};
    vector <int> adj[n];
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    list <int> queue;
    vis[0] = 1;
    queue.push_back(0);
    while(!queue.empty()) {
        int s = queue.front();
        queue.pop_front();
        for (auto i : adj[s]){ 
            if(!vis[i]) {
                vis[i] = true;
                col[i] = col[s] ^ 1;
                queue.push_back(i);
            } 
        } 
    }
    cout << min(accumulate(col, col + n, 0), n - accumulate(col, col + n, 0)) - 1;
}