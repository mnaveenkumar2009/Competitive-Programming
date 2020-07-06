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
        string ans = "no";
        int n, k;
        cin >> n >> k;
        if(n == 1){
            cin >> n;
            if(n == k){
                cout << "yes\n";
            }
            else
                cout << "no\n";
            continue;
        }
        bool we = 0;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i){
                if(a[i - 1] >= k && a[i] >= k)
                    ans = "yes";
                if(i > 1){
                    int x = (a[i - 1] >= k) + (a[i] >= k) + (a[i - 2] >= k);
                    if(x >= 2)
                        ans = "yes";
                }
            }
        }
        if(find(a, a + n, k) == a + n){
            cout << "no\n";
            continue;
        }
        cout << ans << '\n';
    }
}