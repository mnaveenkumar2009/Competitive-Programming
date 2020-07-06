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
        int n, a, b;
        cin >> n >> a >> b;
        int sum = a + b;
        cout << min(max(sum - n + 1, 1LL), n) << ' ' << min(n, sum - 1) << '\n'; 
    }
}