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
        int n, d;
        cin >> n >> d;
        int ans = 0;    
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(i != 0){
                if(d >= x * (i)){
                    ans += x;
                    d -= x * (i);
                }
                else{
                    // cout << ans<<i << d << '\n';
                    ans += d/(i);
                    d -= (d/(i )) * (i);
                }
            }
            else
                ans = x;
        }
        cout << ans << '\n';
    }
}