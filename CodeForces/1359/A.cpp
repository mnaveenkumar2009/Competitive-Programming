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
        int n, m, k;
        cin >> n >> m >> k;
        int x = min(m, n/k);
        int y = (m - x) / (k - 1) + (((m - x) % (k - 1)) > 0);
        cout << x - y << '\n';
    }
}