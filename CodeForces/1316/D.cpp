#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n;
    bool we = 1;
    bool vis[n][n];
    pair <int, int> dest[n][n];
    list <pair <int, int> > queue;
    char ans[n][n];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> x >> y;
            if(x == -1){
                x = 0;
                y = 0;
            }
            x--;
            y--;
            dest[i][j] = {x, y};
            if(x == i && y == j){
                ans[i][j] = 'X';
                queue.push_back({i, j});
            }
        }
    }
    // set cycles;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dest[i][j].first == -1){
                vis[i][j] = 1;
                if(i){
                    if(dest[i-1][j].first == -1){
                        ans[i][j] = 'U';
                        continue;
                    }
                }
                if(i != n - 1){
                    if(dest[i+1][j].first == -1){
                        ans[i][j] = 'D';
                        continue;
                    }
                }
                if(j){
                    if(dest[i][j-1].first == -1){
                        ans[i][j] = 'L';
                        continue;
                    }
                }
                if(j != n - 1){
                    if(dest[i][j+1].first == -1){
                        ans[i][j] = 'R';
                        continue;
                    }
                }
                we = 0;
            }
        }
    }
    while(!queue.empty()) {
        auto s = queue.front();
        queue.pop_front();
        if(vis[s.first][s.second])
            continue;
        vis[s.first][s.second] = 1;
        int i = s.first, j = s.second;

        if(i){
            if(dest[i-1][j] == dest[i][j] && !vis[i-1][j]){
                ans[i-1][j] = 'D';
                queue.push_back({i-1, j});
            }
        }
        if(i != n - 1){
            if(dest[i+1][j] == dest[i][j] && !vis[i+1][j]){
                ans[i+1][j] = 'U';
                queue.push_back({i+1, j});
            }
        }
        if(j){
            if(dest[i][j-1] == dest[i][j] && !vis[i][j-1]){
                ans[i][j-1] = 'R';
                queue.push_back({i, j-1});
            }
        }
        if(j != n - 1){
            if(dest[i][j+1] == dest[i][j] && !vis[i][j+1]){
                ans[i][j+1] = 'L';
                queue.push_back({i, j+1});
            }
        }
    }
    // cout << we << '\n';
    for(int i =0 ; i < n; i++){
        for(int j =0; j < n; j++){
            // cout << vis[i][j] << ' ';
            we &= vis[i][j];
        }
    }
    if(we){
        cout << "VALID\n";
        for(int i =0 ; i < n; i++){
            for(int j = 0; j < n; j++)
                cout << ans[i][j];
            cout << '\n';
        }
    }
    else{
        cout << "INVALID\n";
    }
}