#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0, x;
        cin >> n;
        ans = n * (n + 1);
        ans /= 2;
        vector <int> a(n, 0);
        vector <int> P(2, -1);
        P[1] = n;
        for(int i = 0; i < n; i++){
            cin >> x;
            x = abs(x);
            while(x % 2 == 0){
                if(x == 0){
                    a[i] = 100;
                    break;
                }
                a[i]++;
                x /= 2;
            }
            if(a[i]){
                P.push_back(i);
            }
        }
        sort(P.begin(), P.end());
        // for(auto i:P)cout << i << ' ';cout << '\n';
        for(int i = 1; i < P.size() - 1; i++){
            // cout << i << ' ' << a[P[i]] << '\n';
            if(a[P[i]] == 1){
                ans -= (P[i] - P[i-1]) * (P[i + 1] - P[i]);
            }
        }
        cout << ans << '\n';
    }
}