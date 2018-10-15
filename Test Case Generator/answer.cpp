#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define ll long long

int main()
{
    ll n;
    cin>>n;
    while(cin>>n){
        ll i,j,k,a[n],dp[n][3],ans=1;
        f(i,n){
            cin>>a[i];
            dp[i][0]=dp[i][1]=dp[i][2]=1;
            f(j,i){
                if(a[i]>=a[j]){
                    dp[i][0]=max(1+dp[j][0],dp[i][0]);
                    dp[i][2]=max(1+dp[j][2],dp[i][2]);
                }
                if(-a[i]>=a[j])
                    dp[i][1]=max(1+dp[j][0],dp[i][1]);     
                if(-a[i]>=-a[j])
                    dp[i][1]=max(1+dp[j][1],dp[i][1]);
                if(a[i]>=-a[j])
                    dp[i][2]=max(1+dp[j][1],dp[i][2]);
            }
            f(j,3)ans=max(dp[i][j],ans);
        }
        cout<<ans<<'\n';
    }
    return 0;
}