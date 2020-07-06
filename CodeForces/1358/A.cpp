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
        int n, m;
        cin >> n >> m;
        int ans = (n * m)/2;
        if(n%2 == 1 && m%2 == 1){
            ans += 1;
        }
        cout << ans << '\n';
    }
}