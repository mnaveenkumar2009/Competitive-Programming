#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define ll long long
#define ld long double

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ld dp[n][3];
        dp[0][0] = dp[0][1] = dp[0][2] = 1;
        ld P, Q, R;
        cin >> P >> Q >> R;
        f(i, n-1){
            dp[i + 1][0] = ( dp[i][0] * P + (dp[i][1] + 1) * Q + (dp[i][2] + 1) * R );
            dp[i + 1][1] = ((dp[i][0] + 1) * P + dp[i][1] * Q + (dp[i][2] + 1) * R );
            dp[i + 1][2] = ((dp[i][0] + 1) * P + (dp[i][1] + 1) * Q + (dp[i][2]) * R );
        }
        cout << fixed << setprecision(9) << (dp[n-1][0] * P + dp[n-1][1] * Q + dp[n-1][2] * R)<< '\n';
    }
    return 0;
}