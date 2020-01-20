#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> dp(1e7, 0);
    int n = 1;
    while(n < 1e7){
        dp[n] = dp[n+1] = 1;
        n = 2*n + 1 + (n&1);
    }
    cin >> n;
    cout << dp[n] << '\n';
}