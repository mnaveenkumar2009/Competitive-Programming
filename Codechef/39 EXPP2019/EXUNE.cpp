#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main(){
    #define int long long
    int t;
    cin >> t;
    while(t--){
        int n, k, m;
        cin >> n >> k >> m;
        int A[2];
        A[0] = k;
        A[1] = 1;
        int DP[2];
        DP[1] = 0;
        DP[0] = 1;
        while(m){
            // cout << A[0] << ' ' << A[1] << ' '<< DP[0] << ' '<<DP[1] << '\n';
            if(m&1){
                int X1 = (DP[1] * A[0] + DP[0] * A[1])%mod;
                int X0 = (DP[0] * A[0] + DP[1] * A[1])%mod;
                DP[1] = X1;
                DP[0] = X0;
                m--;
            }
            else
            {
                int X1 = (A[1] * A[0] * 2)%mod;
                A[0] = (A[0] * A[0] + A[1] * A[1])%mod;
                A[1] = X1;
                m/=2;
            }
            // cout << A[0] << ' ' << A[1] << ' '<< DP[0] << ' '<<DP[1] << '\n';
        }
        cout << DP[0] << '\n';

    }
}