#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a[n];
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            a[x-1].push_back(i);
        }
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            int siz = a[i].size();
            for(int j = 0; j < siz - 1; j++){
                ans = min(ans, 1+a[i][j+1] - a[i][j]);
            }
        }
        if(ans == 1e9)
            ans = -1;
        cout << ans << '\n';
    }
}