#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define MAXN 200005
#define int long long
int n, m;
vector <pair <int, bool> > ans;
bool we;
bool vis[MAXN][2];
vector <int> adj[2][MAXN];
pair <int, bool> cyclenode;
unordered_map <int, bool> done;
long long has(long long u, long long v){
    int sum = u + v;
    sum *= sum+1;
    sum /=2;
    return sum + u;
}
int root = -1;
bool dfs(int node, bool parity, int par){
    // cout << node <<' ' << parity << ' ' << par << '\n';
    if(parity)
        done[has(par, node)] = 1;
    else
        done[has(node, par)] = 1;

    vis[node][parity] = 1;
    for(auto nodeadj:adj[parity][node]){
        if(done[has(nodeadj, node)] && parity)
            continue;
        if(done[has(node, nodeadj)] && !parity)
            continue;
        if(vis[nodeadj][1^parity]){
            // if(nodeadj >= root)
            {
                cyclenode = {nodeadj, 1^parity};
                ans.push_back(cyclenode);
                ans.push_back({node, parity});
                we = 1;
                return 1;
            }
            // else
            //     continue;
        }
        else{
            if(dfs(nodeadj, 1 ^ parity, node)){
                ans.push_back({node, parity});
                return 1;
            }
        }
    }
    return 0;
}
signed main(){
    #define int long long
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ans.clear();
        done.clear();
        we = 0;
        cyclenode = {-1, 0};
        cin >> n >> m;
        unordered_map <int, int> XXX;
        for(int i = 0; i < n; i++){
            vis[i][0] = vis[i][1] = 0;
            adj[0][i].clear();
            adj[1][i].clear();
        }
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[0][u-1].push_back(v-1);
            adj[1][v-1].push_back(u-1);
            XXX[has(u-1, v-1)] = i;
        }
        for(int i = 0; i < n; i++){
            if(!vis[i][0]){
                root = i;
                dfs(i, 0, -1);
            }
            if(we)
                break;
            // done.clear();
            for(auto i:ans){
                vis[i.first][i.second]=0;
            }
            ans.clear();
        }
        // for(auto I:ans){
            // cout << I.first + 1 << ' ';
        // }cout << '\n';
        if(we){
            cout << ":)\n";
            bool printing = 0;
            bool plusone = 0;
            vector <int> prin;
            for(int i = 0; i < ans.size() - 1; i++){
                if(ans[i] == cyclenode){
                    if(ans[i].second){
                        plusone = 1;
                    }
                    printing = 1;
                }
                if(printing){
                    if(ans[i].second){
                        prin.push_back(XXX[has(ans[i+1].first, ans[i].first)]);
                    }
                    else{
                        prin.push_back(XXX[has(ans[i].first, ans[i+1].first)]);
                    }
                }
            }
            int kkk = prin.size();
            cout << kkk << '\n';
            for(int i = plusone; kkk--; i++){
                cout << prin[i%((int)prin.size())] + 1 << ' ';
            }
            cout << '\n';
        }
        else
            cout <<":(\n";
    }
}