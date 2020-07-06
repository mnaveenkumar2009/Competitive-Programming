#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>> t;
    while(t--){
        int sum = 0, n, x, m;
        cin >> n >> m;
        while(n--){
            cin >> x;
            sum += x;
        }
        cout << min(sum, m) << '\n';
    }
}