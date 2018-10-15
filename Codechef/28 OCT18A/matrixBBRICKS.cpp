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
ll ds(ll n){
    ll ans=0;
    while(n!=0){
        ans+=n%10;
        n/=10;
    }
    return ans;
}
vvl dp(2000,vl (2000,-1));
ll f2(ll n,ll k){
    if(n<=0)return 0;
    if(k>n)return 0;
    if(k==0)return 1;
    if(dp[n][k]!=-1)
        return dp[n][k];
    dp[n][k]=(f2(n-1,k)+f2(n-1,k-1)+f2(n-2,k-1))%mod;
    return dp[n][k];
}
ll K;
void mul(ll a[],ll b[]){
    ll res[4*K];
    int i, j, k;
    f(i,4*K)res[i]=0;
    f(k,2)
    f(i,2*K){
        f(j,2*K)
            if(j%K<=i%K){
                if(j<K)
                    res[k*2*K+i]=(res[k*2*K+i]+(a[k*2*K+j]*b[i-j])%mod)%mod;
                else
                    res[k*2*K+i]=(res[k*2*K+i]+(a[k*2*K+j]*b[2*K+i-(j%K)])%mod)%mod;
            }
    }
    f(i,4*K){
        a[i]=res[i];
    }
}
int main()
{
    ll t=sc;
    dp[1][1]=2;
    dp[2][2]=2;
    dp[2][1]=4;
    while(t--){
        ll n=sc;
        K=sc;
        if(n<=K+1)
            cout<<f2(n,K)<<'\n';
        else{
            K++;
            ll mat[4*K]={0};
            ll i,j;
            f(i,4*K)mat[i]=0;
            mat[0]=1;
            mat[1]=1;
            mat[K+1]=1;
            mat[2*K]=1;
            
            ll x=n-K;
            ll r[4*K];
            f(i,4*K)r[i]=0;
            r[0]=1;
            for(ll j=0;j<35;j++){
                if((1LL<<j)&x){
                    mul(r,mat);
                }
                if(x>>(j+1))
                    mul(mat,mat);
            }
            ll ans=0;
            f(i,2*K){
                ans=(ans+(f2(K - (i/K),(K-(i+1)%K)%K)*r[i])%mod)%mod;
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}