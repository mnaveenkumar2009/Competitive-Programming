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
        int a, b, n;
        cin >> a >> b >> n;
        int ans = 1;
        while(a + b <= n){
            if(a < b){
                a += b;
            }
            else{
                b += a;
            }
            ans++;
        }
        cout << ans << '\n';
    }
}