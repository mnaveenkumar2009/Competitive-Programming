#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    bool a[n][m], c[n][m];
    memset(c, 0, sizeof(c));
    int b[n][m];
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j] - '0';
            b[i][j] = 1e18 + 1;
        }
    }
    list<pair <pair <int, int>, int> > queue;

    bool vis[n][m];
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i && a[i][j] == a[i-1][j]){
                c[i][j] = 1;
            }
            if(j && a[i][j] == a[i][j-1]){
                c[i][j] = 1;
            }
            if(i != n - 1 && a[i][j] == a[i + 1][j]){
                c[i][j] = 1;
            }
            if(j != m - 1 && a[i][j] == a[i][j + 1]){
                c[i][j] = 1;
            }
            if(c[i][j]){
                queue.push_back({{i, j}, 0});
                vis[i][j] = 1;
                b[i][j] = 0;
            }
        }
    }

    while(!queue.empty()) 
    {
        auto s = queue.front();
        queue.pop_front();
        int i = s.first.first;
        int j = s.first.second;
        b[i][j] = s.second;
        if(i != n - 1){
            if(!vis[i + 1][j]){
                vis[i + 1][j] = 1;
                queue.push_back({{i + 1, j}, s.second + 1});
            }
        }
        if(i){
            if(!vis[i - 1][j]){
                vis[i - 1][j] = 1;
                queue.push_back({{i - 1, j}, s.second + 1});
            }
        }
        if(j){
            if(!vis[i][j - 1]){
                vis[i][j - 1] = 1;
                queue.push_back({{i, j - 1}, s.second + 1});
            }
        }
        if(j != m - 1){
            if(!vis[i][j + 1]){
                vis[i][j + 1] = 1;
                queue.push_back({{i, j + 1}, s.second + 1});
            }
        }
    } 
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << b[i][j] << ' ';
    //     }cout << '\n';
    // }
    while(q--){
        int x, y, F;
        cin >> x >> y >> F;
        if(b[x-1][y-1] <= F)
            F -= b[x-1][y-1];
        else
            F = 0;
        cout << (a[x-1][y-1] ^ (F&1)) << '\n';
    }
}