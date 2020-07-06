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
        int n, ans = 0, x;
        int a[2] = {0, 0};
        cin >> n;
        while(n--){
            cin >> x;
            a[x&1]++;
        }
        cout << a[0] * a[1] << '\n';
    }

}