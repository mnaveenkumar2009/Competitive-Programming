#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int ans[26][26];
    int c[26];
    memset(c, 0, sizeof(c));
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++){
            ans[s[i] - 'a'][j] += c[j];
        }
        c[s[i] - 'a']++;
    }
    int maxi = 0;
    for(int i = 0; i < 26; i++){
        maxi = max(maxi, c[i]);
        for(int j = 0; j < 26; j++){
            maxi = max(maxi, ans[i][j]);
        }
    }
    cout << maxi << '\n';
}