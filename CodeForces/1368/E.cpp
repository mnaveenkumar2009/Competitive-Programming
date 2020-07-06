#include <bits/stdc++.h>
using namespace std;

#define int long long


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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, u, v;
        cin >> n >> m;
        vector <int> adj[n];
        vector <int> par[n];
        int spar[n], s2par[n];
        map <pair <int, int>, int> done;
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            u--;v--;
            if(done[{u,v}])continue;
            adj[u].push_back(v);
            par[v].push_back(u);
            done[{u, v}] = 1;
        }
        set <pair <int, int> > S;
        vector <int> rem;
        for(int i = 0; i < n; i++){
            spar[i] = par[i].size();
            s2par[i] = 0;
            for(auto j:par[i]){
                s2par[i] += par[j].size();
            }
            if(s2par[i] != 0){
                S.insert({s2par[i], i});
            }
        }
        vector <bool> removedd(n, 0);
        while(S.size() > 0){
            // cout << "hi\n";
            // for(auto it:S){
            //     cout << it.first << ' ' << it.second << '\n';
            // }
            auto it = S.end();
            it--;
            auto s = *(it);
            int x = s.second;
            removedd[x] = 1;
            S.erase(it);
            rem.push_back(x);
            vector<int> v;
            for(auto i: adj[s.second]){
                S.erase({s2par[i], i});
                s2par[i] -= spar[x];
                spar[i] -= 1;
                v.push_back(i);
                for(auto j:adj[i]){
                    S.erase({s2par[j], j}); // hopefully erase twice doesnt cause a bug
                    s2par[j]--;
                    v.push_back(j);
                }
            }
            for(auto i:v){
                if(!removedd[i])
                    S.insert({s2par[i], i}); // not a multiset so no issues
            }
        }
        assert(rem.size() * 7 <= 4 * n);
        cout << rem.size() << '\n';
        for(auto i:rem)cout << i + 1<< ' ';
        cout << '\n';
    }
}