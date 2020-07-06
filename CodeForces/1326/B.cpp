#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t =1;
    // cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], b[n];
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        int maxi = 0;
        for(int i = 0; i < n; i++){
            a[i] = b[i] + maxi;
            maxi = max(maxi, a[i]);
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}