#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unordered_map <int, int> ans;
    // memset(ans, 0, sizeof(ans));
    int x, n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        ans[x - i ] += x;
        // cout << x - i << '\n';
    }
    // cout << *max_element(ans, ans + 2000006) << '\n';
    int maxi = 0;
    for(auto i:ans){
        maxi = max(i.second, maxi);
    }
    cout << maxi << '\n';
}