#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> k >> m;
        int dp[k+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        while(n--){
            int x;
            cin >> x;
            x %= m;
            for(int j = 105; j >= (x==0); j--)
                if(j*m+x<=k)
                    dp[j*m + x] = (dp[j*m + x] + dp[j*m + x - 1])%1000000007;
            dp[0] = 1;
        }
        cout << dp[k] << '\n';
    }
	return 0;
}