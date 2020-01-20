#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    string s;
    cin >> s;
    int n = s.size();
    for(auto i:s){
        if(i=='m' || i=='w'){
            cout << "0\n";
            return 0;
        }
    }
    int dp[n];
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        dp[i] = dp[i-1];
        if(s[i] == 'n' && s[i-1] == 'n'){
            dp[i] = dp[i-1] + (i>1?dp[i-2]:1);
        }
        if(s[i] == 'u' && s[i-1] == 'u'){
            dp[i] = dp[i-1] + (i>1?dp[i-2]:1);
        }
        dp[i] %= 1000000007;
    }
    cout  << dp[n-1] << '\n';
    return 0;
}