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
        int n;
        cin >> n;
        int a[n], ans = 1;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for(int i = n - 1; i >= 0; i--){
            if(a[i] <= i + 1){
                ans += i + 1;
                break;
            }
        }
        cout << ans << '\n';
    }
}