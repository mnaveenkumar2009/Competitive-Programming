#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mod 987654319
int main(){
    #define int long long
    int n;
    cin >> n;
    int a[n];
    int DP[n][7];
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        for(int j = 0; j < 7; j++)
            DP[i][j] = 0;
        DP[i][0] = 1;
        for(int j = 0; j < i; j++){
            if(a[j] < a[i]){
                DP[i][2] = (DP[i][2] + DP[j][1])%mod;
                DP[i][5] = (DP[i][5] + DP[j][4])%mod;
            }
            if(a[j] > a[i]){
                DP[i][1] = (DP[i][1] + DP[j][0])%mod;
                DP[i][3] = (DP[i][3] + DP[j][2])%mod;
                DP[i][4] = (DP[i][4] + DP[j][3])%mod;
                DP[i][6] = (DP[i][6] + DP[j][5])%mod;
            }
        }
        ans = (ans + DP[i][6])%mod;
    }
    cout << ans << '\n';
}