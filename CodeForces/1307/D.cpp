#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int A[200005], B[200005];
    int n, m, k, u, v;

    cin >> n >> m >> k;
    bool a[n];
    memset(a, 0, sizeof(a));
    for(int i =0; i < k; i++){
        cin >> u;
        a[u-1] = 1;
    }

    vector <int> adj[n];

    for(int i = 0; i < m; i++){
        cin >> u >> v;
        adj[u-1].push_back(v - 1);
        adj[v-1].push_back(u - 1);
    }
    bool vis[n];
    memset(vis, 0, sizeof(vis));

    list <pair <int, int> > queue;
    queue.push_back({0, 0});
    while(!queue.empty()) {
        auto s = queue.front();
        queue.pop_front();
        if(vis[s.first])
            continue;
        vis[s.first] = 1;
        A[s.first] = s.second;
        for(int i:adj[s.first]){
            if (!vis[i]){
                queue.push_back({i, s.second+1});
            }
        } 
    }
    queue.clear();
    memset(vis, 0, sizeof(vis));
    queue.push_back({n - 1, 0});
    while(!queue.empty()) {
        auto s = queue.front();
        queue.pop_front();
        if(vis[s.first])
            continue;
        vis[s.first] = 1;
        B[s.first] = s.second;
        for(int i:adj[s.first]){
            if (!vis[i]){
                queue.push_back({i, s.second+1});
            }
        } 
    }
    vector<pair <int, int> > Ans;
    int ans = A[n - 1], ans2 = 0;
    for(int i = 0; i < n; i++){
        // cout << A[i] << ' ' << B[i] << '\n';
        // cout << a[i] << ' ';
        if(a[i]){
            Ans.push_back({A[i] - B[i], i});
        }
    }
    sort(Ans.begin(), Ans.end());
    int Maxi[k];
    for(int i = 0; i < k; i++){
        Maxi[i] = A[Ans[i].second];
        if(i){
            Maxi[i] = max(Maxi[i], Maxi[i-1]);
            // cout << "mas " << Ans[i].second << '\n';
            ans2 = max(ans2, Maxi[i-1] + B[Ans[i].second] + 1);
        }
        // cout << ans2 << '\n';
    }
    ans = min(ans, ans2);
    cout << ans << '\n';
}