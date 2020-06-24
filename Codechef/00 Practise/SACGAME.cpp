#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define sd(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define slld(n) scanf("%lld",&n)
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
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

ll gc(ll px,ll py,ll qx,ll qy)
{
    if (px==qx)
        return abs(py - qy) - 1;
    
    if (py == qy)
        return abs(px-qx) - 1;
 
    return (__gcd(abs(px-qx), abs(py-qy))-1)%mod;
}
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
ll nc2(ll n){
    
    ll ret=n%mod;
    ret=ret*(ret-1);
    ret%=mod;
    ret=ret*pr(2,mod-2);
    ret%=mod;
    return ret;
}
ll nc3(ll n){
    ll ret=n%mod;
    ret = ((ret*(ret-1))%mod)*(ret-2);
    ret%=mod;
    ret*=pr(6,mod-2);
    ret%=mod;
    return (ret+mod)%mod;
}
int main()
{
    
    ll dp[109][109][109];
    
    ll i,j,k;
    f(i,109)f(j,109)f(k,109){
        dp[i][j][k]=0;
    }
    dp[0][0][0]=1;
    dp[1][1][1]=1;
    f(i,109){
        f(j,109){
            if(i&&j)
                dp[i][j][1]=1;
        }
    }
    ll sum[109][109][109];
    f(i,109){
        f(j,109){
            f(k,109){
                if(i!=j)
                    sum[i][j][k]=dp[i][j][k];
            }
        }
    }
    
    f(i,109){
        f(j,109){
            f(k,109){
                
                if(i-1>=0)
                    sum[i][j][k]+=sum[i-1][j][k];
                if(j-1>=0)
                    sum[i][j][k]+=sum[i][j-1][k];
                if(i-1>=0&&j-1>=0)
                    sum[i][j][k]-=sum[i-1][j-1][k];
                sum[i][j][k]%=mod;
            }
        }
    }
    f(k,109){
        f(i,109){
            f(j,109){
                if(i<k||j<k)
                    continue;
                if(k==0)continue;
                ll u,v;
                // f(u,i){
                //     f(v,j){
                //         if(u!=v){
                //             dp[i][j][k]+=dp[u][v][k-1];
                //         }
                //     }
                // }
                if(i-1>=0&&j-1>=0)
                    dp[i][j][k]+=sum[i-1][j-1][k-1]%mod;
                dp[i][j][k]%=mod;
            }
        }
        f(i,109){
            f(j,109){
                sum[i][j][k]=0;
                if(i!=j)
                    sum[i][j][k]=dp[i][j][k];
                if(i-1>=0)
                    sum[i][j][k]+=sum[i-1][j][k];
                if(j-1>=0)
                    sum[i][j][k]+=sum[i][j-1][k];
                if(i-1>=0&&j-1>=0)
                    sum[i][j][k]-=sum[i-1][j-1][k];
                sum[i][j][k]%=mod;
            }
        }
    }
    
    // f(k,5){
    //     f(i,10){
    //         f(j,10){
    //             cout<<dp[i][j][k]<<' ';
    //         }cout<<'\n';
    //     }pc('\n');
    // }
    ll t=uscan();
    while(t--){
        ll n=uscan();        
        ll k=uscan();
        if (n > k) {
            cout<<"0\n";
        }
        else
            cout<<(dp[k][k][n]+mod)%mod<<'\n';
    }
    return 0;
}