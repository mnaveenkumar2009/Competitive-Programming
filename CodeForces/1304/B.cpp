#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    string ans = "", pal = "";
    map <string, bool> S;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        S[s] = 1;
        reverse(s.begin(), s.end());
        S[s];
    }
    for(auto i:S){
        if(i.second == 0)continue;
        string b = i.first;
        // cout << i.first << '\n';
        reverse(b.begin(), b.end());
        if(b == i.first){
            if(pal.size() < b.size())
                pal = b;
        }
        else{
            if(S[b]){
                S[b] = 0;
                ans = i.first + ans + b;
            }
        }
    }
    n = ans.size();
    ans = ans.substr(0, n/2) + pal + ans.substr(n/2, n/2);
    cout << ans.size() << '\n';
    cout << ans << '\n';
}