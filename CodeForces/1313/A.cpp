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
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if(a[0] >= 4){
            cout << "7\n";
        }
        else{
            int ans = 0;
            a[1] = min(a[1], 3LL);
            a[2] = min(a[2], 3LL);
            if(a[0] == 0){
                ans = ((a[1] > 1) && (a[2] > 1)) + (a[1] >= 1) + (a[2] >= 1);
            }
            if(a[0] == 1){
                ans = ((a[1] > 1) && (a[2] > 1)) + 3;
            }
            if(a[0] == 2){             
                ans = 4;
                ans += (a[2] == 3);
            }
            if(a[0] == 3)
                ans = 6;
            cout << ans << '\n';
        }
    }
}