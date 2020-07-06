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
        int n, m, x, y, ans = 0;
        cin >> n >> m >> x >> y;
        y = min(2 *x, y);
        for(int i = 0; i < n; i++){
            string s;
            int c = 0;
            cin >> s;
            for(int j = 0; j < m; j++){
                if(s[j] == '.')c++;
                else{
                    ans += (c/2) * y + (c%2) * x;
                    c = 0;
                }
            }
            ans += (c/2) * y + (c%2) * x;
        }
        cout << ans << '\n';
    }
}