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
        int n, x, ans = 0;
        cin >> n >> x;
        int a[n];
        int D[n][n];
        memset(D, 0, sizeof(D));
        vector <int> P[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++){
            int maxi = a[i], mini = a[i];
            for(int j = i; j < n; j++){
                maxi = max(maxi, a[j]);
                mini = min(mini, a[j]);
                if(maxi - mini == j - i){
                    P[i].push_back(j);
                    D[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = n - 2; j >= i; j--){
                D[i][j] += D[i][j + 1];
            }
        }
        for(int i = 0; i < n; i++){
            for(auto j: P[i]){
                if(j - i < x)
                    continue;
                // start from i + 1 to j - (x - 1)
                ans += D[j - (x - 1)][]
            }
        }
    }
}