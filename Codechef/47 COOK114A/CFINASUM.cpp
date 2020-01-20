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
        int n, ans = 0;
        cin >> n;
        int a[n], sum[n];
        unordered_map <int, vector <int> > M;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum[i] = a[i];
            if(i){
                sum[i] += sum[i-1];
            }
            if(i != n - 1)
                M[sum[i]].push_back(i);
        }
        for(int i = 0; i < n; i++){
            int cur = sum[n - 1] - a[i];
            if(cur&1)continue;
            cur /= 2;
            auto pos = upper_bound(M[cur].begin(), M[cur].end(), i - 1);
            ans += pos - M[cur].begin();
            auto pos2 = lower_bound(M[cur + a[i]].begin(), M[cur + a[i]].end(), i);
            ans += M[cur + a[i]].end() - pos2;
            // cout << ans << '\n';
        }
        cout << ans << '\n';
    }
}