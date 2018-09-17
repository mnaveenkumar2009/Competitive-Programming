#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define f(i,n) for(i=0;i<n;i++)
#define sc uscan()
inline ll uscan()
{
    ll n=0,c=gc();
    bool check=0;
    if(c=='-')check=1;
    while(c<'0'||c>'9')
    {
        c=gc();
        if(c=='-')check=1;
    }
    while(c<='9'&&c>='0'){
        n=n*10+c-'0';
        c=gc();
    }
    return n+(-2*check*n);
}
#define N 100008
#define H 64

ll dp[N][H],sum[N][H],sum2[N][H];
ll f2(ll n,ll h){
    
    if(h==1){
        dp[n][h]=1;
        return 1;
    }
    if(dp[n][h]!=-1){
        return dp[n][h];
    }
    ll ret=1;
    for(ll i=1;2*i<n;i++){
        // n-i first row i left     (n-i-1) - (i-1)
        ret=(ret+((n-2*i)*f2(i,h-1))%mod)%mod;
    }
    dp[n][h]=ret;
    return ret;
}
int main() {
    ll h=sc,n=sc;
    h=min(h,(ll)H);
    ll i,j,k;
    f(i,N){
        f(j,H){
            dp[i][j]=-1;
            sum[i][j]=0;
            sum2[i][j]=0;
        }
    }
    cout<<f2(8,1)<<'\n';
    cout<<f2(20,3)<<'\n';
    cout<<f2(21,3)<<'\n';
    cout<<f2(20,4)<<'\n';
    cout<<f2(21,4)<<'\n';
    
    f(i,N){
        dp[i][0]=0;
        dp[i][1]=1;
    }
    dp[0][0]=1;
    f(i,H-1){
        dp[0][i+1]=1;
        dp[1][i+1]=1;
        dp[2][i+1]=1;
    }
    f(i,N){
        f(j,H){
            sum[i][j]=dp[i][j];
            sum2[i][j]=(i*dp[i][j])%mod;
        }
    }
    f(i,N){
        if(i<2)continue;
        f(j,H){
            sum[i][j]=(sum[i][j]+sum[i-1][j])%mod;
            sum2[i][j]=(sum2[i][j]+sum2[i-1][j])%mod;
        }
    }

    f(j,H){
        if(j==0)continue;
        f(i,N){
            dp[i][j]=( 1 + (sum[n/2-1][j-1])%mod - (2*sum2[n/2-1][j-1])%mod +mod)%mod;
        }

        f(i,N){
            sum[i][j]=dp[i][j];
            sum2[i][j]=(i*dp[i][j])%mod;
        }
        f(i,N){
            sum[i][j]=(sum[i][j]+sum[i-1][j])%mod;
            sum2[i][j]=(sum2[i][j]+sum2[i-1][j])%mod;
        }
    }
    
    // f(i,20){
    //     f(j,20){
    //         cout<<f2(i,j)<<' ';
    //     }
    //     cout<<'\n';
    // }
    f(i,20){
        f(j,20){
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    // cout<<f2(100000,63)<<'\n';

    cout<<dp[n][h];
    return 0;
}