#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        bool vis[n];
        string S[n];
        memset(vis, 0, sizeof(vis));
        vis[0] = 1;
        for(int i = 0; i < n; i++){
            cin >> S[i];
        }
        int ans = -1;
        list<pair <int, int> > queue;
        queue.push_back({0, 0});
        while(!queue.empty()) {
            auto s = queue.front();
            if(s.first == n - 1){
                ans = s.second;
                break;
            }
            queue.pop_front();
            for (int i = 0; i < n; i++){
                if (!vis[i]){
                    if(abs(i - s.first) <= k && S[s.first][i] == '1'){
                        vis[i] = true;
                        queue.push_back({i, s.second+1});
                    }
                }
            } 
        }
        cout << ans << '\n';
    }
}