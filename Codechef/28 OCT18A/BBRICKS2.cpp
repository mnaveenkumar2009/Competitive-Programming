#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define sort1(a) sort(a.begin(),a.end())
#define sort2(a,n) sort(a,a+n)
#define vl vector <ll>
#define vvl vector <vector <ll> >
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
#define sc uscan()
void prin(vector <ll> a){
    ll i;
    f(i,a.size()/2){
        cout<<a[i]<<' ';
    }pc('\n');

    f(i,a.size()/2){
        cout<<a[a.size()/2+i]<<' ';
    }pc('\n');
}
void prin(ll a[],ll n){
    ll i;
    f(i,n/2){
        cout<<a[i]<<' ';
    }pc('\n');

    f(i,n/2){
        cout<<a[n/2+i]<<' ';
    }pc('\n');
}
void prin(vector <vector <ll> > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j]<<' ';
        pc('\n');
    }
    pc('\n');
}
void prin(vector <vector <pair <ll,ll> > > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j].ss<<' ';
        pc('\n');
    }
    pc('\n');
}
vvl dp(2000,vl (2000,-1));
vvl dp2(3000,vl (3000,-1));
ll D(ll n,ll k){
    if(n<0)return 0;
    if(k<0)return 0;
    if(dp2[n][k]!=-1)
        return dp2[n][k];
    if(n==0||k==n){
        return 1;
    }
    dp2[(n)][(k)] = (D(n-1, k-1)+D(n-2, k-1)+D(n-1, k))%mod;
    return dp2[n][k];
}
ll f2(ll n,ll k){
    if(n<=0)return 0;
    if(k>n)return 0;
    if(k==0)return 1;
    if(dp[n][k]!=-1)
        return dp[n][k];
    dp[n][k]=(f2(n-1,k)+f2(n-1,k-1)+f2(n-2,k-1))%mod;
    return dp[n][k];
}
#define K 1001
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
ll ncr(ll n, ll k) 
{ 
    ll res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if ( k > n - k ) 
        k = n - k; 
  
    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1] 
    for (ll i = 0; i < k; ++i) 
    { 
        res *= (n - i); 
        res%=mod;
        res *= pr(i + 1,mod-2); 
        res%=mod;
    } 
  
    return res; 
} 
int main()
{
    ll t=sc;
    dp[1][1]=2;
    dp[2][2]=2;
    dp[2][1]=4;
    ll i,j;
    // ll m[31][4*K]={0};
    // ll i,j;
    // f(j,31)f(i,4*K)m[j][i]=0;
    // m[0][0]=1;
    // m[0][1]=1;
    // m[0][K+1]=1;
    // m[0][2*K]=1;
    // ll jj;
    // for(jj=1;jj<31;jj++){
    //     f(i,4*K)m[jj][i]=0;
    //     ll kkkk;
    //     f(kkkk,2)
    //     f(i,2*K){
    //         f(j,2*K)
    //             if(j%K<=i%K){
    //                 if(j<K)
    //                     m[jj][kkkk*2*K+i]=(m[jj][kkkk*2*K+i]+(m[jj-1][kkkk*2*K+j]*m[jj-1][i-j])%mod)%mod;
    //                 else
    //                     m[jj][kkkk*2*K+i]=(m[jj][kkkk*2*K+i]+(m[jj-1][kkkk*2*K+j]*m[jj-1][2*K+i-(j%K)])%mod)%mod;
    //             }
    //     }
    // }
    // f(i,10){
    //     f(j,4*K)
    //     if(m[i][j])
    //     cout<<"m["<<i<<"]"<<"["<<j<<"]="<<m[i][j]<<';';
    // }
    while(t--){
        ll n=sc;
        ll k=sc;
        if(n<=k+3)
            cout<<f2(n,k)<<'\n';
        else{
            // k++;
            
            // ll x=n-k;
            // ll r[4*K]={0};
            // f(i,4*K)r[i]=0;
            // r[0]=1;
            // for(ll jjj=0;jjj<30;jjj++){
            //     if((1LL<<jjj)&x){
            //         // mul(r,m[j]);
            //         ll ress[4*K];
            //         f(i,4*K)ress[i]=0;
            //         ll kkkk;
            //         f(kkkk,2)
            //         f(i,2*K){
            //             f(j,2*K)
            //                 if(j%K<=i%K){
            //                     if(j<K)
            //                         ress[kkkk*2*K+i]=(ress[kkkk*2*K+i]+(ress[kkkk*2*K+j]*m[jjj][i-j])%mod)%mod;
            //                     else
            //                         ress[kkkk*2*K+i]=(ress[kkkk*2*K+i]+(ress[kkkk*2*K+j]*m[jjj][3*K+i-j])%mod)%mod;
            //                 }
            //         }
            //         f(i,4*K)r[i]=ress[i];
            //     }
            // }

            // f(i,K)r[i]=D(x,i);
            // for(i=K;i<2*K;i++)r[i]=D(x-1,i);
            ll ans=0;
            // f(i,2*K){
            //     ans=(ans+(f2(K - (i/K),(K-(i+1)%K)%K)*r[i-(K-k)])%mod)%mod;
            // }
            for(i=1;i<=k;i++){
                ans=(ans+( (  ( pr(2,i)*(ncr(n-k+1,i)) )%mod ) * (ncr(k-1,i-1)) ) )%mod;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}