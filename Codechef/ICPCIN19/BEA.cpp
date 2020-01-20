#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(t--){
        vector <int> ans;
        int n, k;
        cin >> n >> k;
        int sum = 0, cur = 0;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
            cout << sum << '\n';
            if(sum > 0){
                sum = 0;
                ans.push_back((i + 1) - cur);
                cur += i + 1 - cur;
                if(ans.size() == k -1){
                    for(i++; i < n; i++){
                        sum += a[i];
                    }
                    ans.push_back(n - cur);
                }
                cout << cur << '\n';
            }
        }
        if(ans.size() == k){
            cout << "YES\n";
            for(auto i:ans){
                cout << i << ' ';
            }
            cout << '\n';
        }
        else{
            cout << "NO\n";
        }
    }
}