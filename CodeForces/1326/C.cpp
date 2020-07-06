#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k, ans = 0, fans = 1;
    cin >> n >> k;
    vector <int> a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x >= n - k + 1){
            a.push_back(i);
            ans += x;
        }
    }    
    for(int i = 0; i < a.size() - 1; i++){
        fans *= (a[i+1] - a[i]);
        fans %= mod;
    }
    cout << ans << ' ' << fans;
}