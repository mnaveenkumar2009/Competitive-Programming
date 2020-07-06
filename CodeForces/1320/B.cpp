#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> adj[200005], adj2[200004];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj2[v-1].push_back(u-1);
    }


    int k;
    cin >> k;
    int p[k];
    for(int i = 0; i < k; i++){
        cin >> p[i];
        p[i]--;
    }

    int dist[n];
    bool vis[n];
    memset(vis, 0, sizeof(vis));

    list <pair <int, int> > queue;
    queue.push_back({p[k-1], 0});
    while(!queue.empty()) {
        auto s = queue.front();
        queue.pop_front();
        if(vis[s.first])
            continue;
        vis[s.first] = 1;
        dist[s.first] = s.second;
        for(int i:adj2[s.first]){
            if (!vis[i]){
                queue.push_back({i, s.second+1});
            }
        } 
    }
    int mini = 0, maxi = 0;

    for(int i = 0; i < k - 1; i++){
        if(dist[p[i + 1]] != dist[p[i]] - 1){
            mini++;
            maxi++;
        }
        else{
            int coun = 0;
            for(auto ad:adj[p[i]]){
                if(dist[ad] == dist[p[i]] - 1){
                    coun++;
                }
            }
            if(coun > 1){
                maxi++;
            }
        }
    }
    cout << mini << ' ' << maxi << '\n';
}