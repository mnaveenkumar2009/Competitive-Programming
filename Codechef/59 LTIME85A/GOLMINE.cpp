#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ld g[n], a[n], b[n], ans1 = 0, ans2 = 0;
        vector <pair <ld, int> > A, B;
        for(int i = 0; i < n; i++){
            int x, y, z;
            cin >> x >> y >> z;
            g[i] = x;
            a[i] = y;
            b[i] = z;
            // A.push_back({g[i]/a[i], i});
            // B.push_back({g[i]/b[i], i});
            ans1 += (g[i] * b[i]) / (a[i] + b[i]);
            ans2 += (g[i] * a[i]) / (a[i] + b[i]);
        }
        cout << fixed << setprecision(9) << ans1 << ' ' << ans2 << '\n';
    }
}