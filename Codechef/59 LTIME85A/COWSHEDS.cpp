#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int b[n];
    vector <int> a[n];
    for(int i = 0; i < n; i++){
        a[i].push_back(i);
        b[i] = i;
    }
    int ans = n;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;r--;
        for(int i = l; i <= r; i++){
            // i, r-(l-i)
            int B1 = min(b[i], b[r-(i-l)]);
            int B2 = max(b[i], b[r-(i-l)]);
            if(B1 == B2)continue;
            ans--;
            for(auto j:a[B2]){
                b[j] = B1;
                a[B1].push_back(j);
            }
            a[B2].clear();
        }
        cout << ans << '\n';
    }
    
}