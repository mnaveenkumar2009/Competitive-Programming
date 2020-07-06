#include <bits/stdc++.h>
using namespace std;
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0, x;
        cin >> n;
        while(n--){
            cin >> x;
            ans = max(ans, x);
        }
        cout << ans << '\n';
    }

}