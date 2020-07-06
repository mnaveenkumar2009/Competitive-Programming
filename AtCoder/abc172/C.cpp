#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int a[n], b[m];
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i)
            a[i] += a[i-1];
        if(a[i] <= k){
            ans = i + 1;
        }
        // cout << a[i] << ' ';
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
        if(i)
            b[i] += b[i-1];
        // cout << k - b[i] << ' ';
        // cout << (upper_bound(a, a + n, k - b[i]) - a) << '\n';
        if(b[i] <= k){
            ans = max(ans, i + 1 + (upper_bound(a, a + n, k - b[i]) - a));
        }
    }
    cout << ans << '\n';
}