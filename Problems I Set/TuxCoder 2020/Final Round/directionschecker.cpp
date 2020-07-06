#include <bits/stdc++.h>
using namespace std;

long long has(long long a, long long b){
    long long sum = a + b;
    sum = (sum * (sum + 1)) + min(a, b);
    return sum;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unordered_map <int, bool> done;
    unordered_map <int, int> edge_num;
    int n, m;
    cin >> n >> m;
    vector <int> adj[n];
    pair <int, int> ED[m];

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ED[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
        assert(!done[has(u, v)]);
        done[has(u, v)] = 1;
        edge_num[has(u, v)] = i;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < adj[i].size(); j++){
            int e1 = edge_num[has(adj[i][j], i)]; 
            for(int j2 = j + 1; j2 < adj[i].size(); j2++){
                if(!done[has(adj[i][j], adj[i][j2])]){
                    int e2 = edge_num[has(adj[i][j2], i)];
                    int nm1 = 2 * e1, nm2 = 2 * e2;
                    if(adj[i][j] < i)
                        nm1 ^= 1;
                    if(adj[i][j2] < i)
                        nm2 ^= 1;
                    // cout << nm1 << ' ' << nm2 << '\n';
                    Add(nm1, nm2 ^ 1);
                }
            }
        }
    }

    cout << 1 << '\n';
}