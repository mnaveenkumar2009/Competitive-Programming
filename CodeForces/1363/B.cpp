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
        string s;
        cin >> s;
        int n = s.size();
        int pre[n], suf[n];
        for(int i = 0; i < n; i++){
            pre[i] = s[i] == '1';
            if(i){
                pre[i] += pre[i-1];
            }
        }
        for(int i = n - 1; i >= 0; i--){
            suf[i] = s[i] == '0';
            if(i != n - 1){
                suf[i] += suf[i+1];
            }
        }
        int ans = min(pre[n-1], suf[0]);
        for(int i = 0; i < n - 1; i++){
            ans = min(ans, pre[i] + suf[i + 1]);
        }

        for(int i = 0; i < n; i++){
            pre[i] = s[i] == '0';
            if(i){
                pre[i] += pre[i-1];
            }
        }
        for(int i = n - 1; i >= 0; i--){
            suf[i] = s[i] == '1';
            if(i != n - 1){
                suf[i] += suf[i+1];
            }
        }
        ans = min(ans, pre[n-1]);
        ans = min(ans, suf[0]);
        for(int i = 0; i < n - 1; i++){
            ans = min(ans, pre[i] + suf[i + 1]);
        }
        cout << ans << '\n';
    }
}