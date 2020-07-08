#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        int x, y, a, b;
        cin >> a >> b >> x >> y;
        if(a > b){
            swap(a, b);
        }
        int ans = (b - a)* x;
        ans += min(y, 2*x) * a;
        cout << ans << '\n';
    }
}