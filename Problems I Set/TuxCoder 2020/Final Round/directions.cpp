#include <bits/stdc++.h>
using namespace std;
// 2 sat template : https://cp-algorithms.com/graph/2SAT.html

int n, m, cl;

int vis[2000001];
vector<int> g[2000006], gt[2000006], ad[2000001];
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int &u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    for (int &u : gt[v^1]) {
        if (!used[u^1])
            dfs1(u^1);
    }
    order.push_back(v);
}

void dfs2(int v) {
    comp[v] = cl;
    for (int &u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u);
    }
    for (int &u : g[v^1]) {
        if (comp[u^1] == -1)
            dfs2(u^1);
    }
}

bool solve_2SAT() {
    n = m * 2;
    used.clear();
    comp.clear();
    assignment.clear();
    order.clear();
    used.resize(n);
    comp.resize(n);
    assignment.resize(n);
    used.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    cl = 0;
    for (int i = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1){
            dfs2(v);
            cl++;
        }
    }

    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

void Add(int u, int v){
    g[u].push_back(v);
    gt[v].push_back(u);
}

long long has(long long a, long long b){
    long long sum = a + b;
    sum = (sum * (sum + 1)) + min(a, b);
    return sum;
}

bool findLoop(int v) {
    if(vis[v]==1)
        return 1;
    if(vis[v]==2)
        return 0;
    vis[v]=1;
    for(auto &it:ad[v]){
        if(findLoop(it)){
            return 1;
        }
    }
    vis[v] = 2;
    return 0;
}

bool checkLoop(int n) {
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            // cout << "NOT vis\n";
            // cout << i << '\n';
            // for(int j = 0; j < n; j++)
            //     cout << vis[j];
            // cout << '\n';
            if(findLoop(i)){
                // cout << "found " << i << '\n';
                return 1;
            }
        }
    }
    return 0;
}
signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        unordered_map <int, bool> done;
        unordered_map <int, int> edge_num;
        int n;
        cin >> n >> m;
        vector <int> adj[n];
        pair <int, int> ED[m];
        for(int i = 0; i < 2*m; i++){
            g[i].clear();
            gt[i].clear();
        }
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
        for(int i = 0; i < n; i++)
            ad[i].clear();

        string ans(m, 'v');
        if(solve_2SAT()){
            for(int i = 0; i < m; i++){
                if(!(assignment[i] ^ (ED[i].first < ED[i].second))){
                    ans[i] = ('^');
                    ad[ED[i].first].push_back(ED[i].second);
                }
                else
                    ad[ED[i].second].push_back(ED[i].first);
            }
        }
        else
            ans = "No solution";
        if(checkLoop(n)){
            ans = "No solution";
        }
        cout << ans << '\n';
    }
}