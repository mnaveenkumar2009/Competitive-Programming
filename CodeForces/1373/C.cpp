#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans = s.size(), cur = 0, pos = 1;
        for(auto i:s){
            if(i == '+'){
                cur++;
            }
            else{
                cur--;
                if(cur < 0){
                    ans += pos;
                    cur = 0;
                }
            }
            pos++;
        }
        cout << ans << '\n';
    }
}