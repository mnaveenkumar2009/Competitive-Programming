#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[3006][3006];
#define mod 998244353
int a, b, c, d;
int f(int x, int y){
    if(dp[x][y] != -1)return dp[x][y];
    if(x == a){
        if(y == b){
            return dp[x][y] = 1;
        }
        else
            return dp[x][y] = (f(x, y - 1) * x) % mod;
    }
    else{
        if(y == b){
            return dp[x][y] = (f(x - 1, y) * y) % mod;
        }
        else{
            return dp[x][y] = (f(x, y - 1) * x + f(x - 1, y) * y - (((x-1) * (y - 1))%mod) * f(x - 1, y - 1)) % mod;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> a >> b >> c >> d;
    cout << (f(c, d) + mod) % mod << '\n';
}