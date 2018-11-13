#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define mod 1000000007
#define ll long long

ll dp[2600][2600];
ll pr(ll x, ll y)
{
    ll res = 1; 

    x = x % mod;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;

        y = y>>1; // y = y/2
        x = (x*x) % mod;  
    }
    return res;
}
ll f2(ll n,ll m){
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(n==1){
        return 1;
    }
    // ll ret= ((m*(m+1))/2+f2(n-1,m))%mod;
    ll ret=0;
    ll i,j;
    // for(i=1;i<m;i++){
    //     for(j=1;j<i;j++){
    //         ret=(ret+f2(n-1,m-j))%mod;
    //     }
    // }
    for(i=1;i<=m;i++){
        for(j=i;j<=m;j++){
            for(ll k=1;k<=n;k++){
                // conect to 
            }
        }
    }
    ret+=pr(n-1,m);
    return ret;
}
int main(){
    ll i,j,k;
    f(i,2600){
        f(j,2600){
            dp[i][j]=-1;
        }
    }
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        cout<<f2(n,m)<<'\n';
    }
}