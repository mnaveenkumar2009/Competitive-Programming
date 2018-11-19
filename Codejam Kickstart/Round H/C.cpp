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
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin(ll a[],ll n){
    ll i;
    f(i,n){
        cout<<a[i]<<' ';
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
void prin(vector < pair<ll,ll> > a){
    ll i,j;
    f(i,a.size()){
        cout<<a[i].ff<<' '<<a[i].ss<<'\n';
    }
    pc('\n');
}
#define vl vector <ll> 
#define vvl vector <vector <ll> >
#define vpl vector <pair <ll,ll> >
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
vl fact(1000006);
ll mul(ll a,ll b){
    return (a*b)%mod;
}
ll f2(ll x){
    ll temp=((x*(x+1))/2)%mod;
    ll temp2=fact[x];
    return (((temp*temp2)%mod)*2LL)%mod;
}
int main()
{
    ll tt=sc,kkk;
    // cout<<tt<<'\n';
    ll i,j;
    fact[0]=1;
    fact[1]=1;

        //  a(n-1) + 4*n - 3
    vl xxx(1000006);
    xxx[0]=0;
    xxx[1]=1;
    for(i=2;i<1000006;i++){
        xxx[i]=(xxx[i-1]+4*i - 3)%mod;
    }
    f(i,10){
        cout<<xxx[i]<<'\n';
    }
    f(i,1000006){
        if(i>1){
            fact[i]=(i*fact[i-1])%mod;
        }
    }
    f(kkk,tt){
        ll n=sc,m=sc;
        ll ans=0;
        if((n==m)&&(m==1)){
            cout<<"Case #"<<kkk+1<<": "<<ans<<'\n';
            continue;
        }
        ll dp[m];
        dp[0]=f2(2*(n-1));
        // cout<<dp[0]<<' ';

        f(i,m-1){
            // m=i+2
            // cout<<"zd"<<mul(n-1,mul(n,pr(2,i+1)))<<'\n';
            dp[i+1]=(dp[i]-(pr(mul(xxx[n-1],pr(2,i+1)),2))+mod)%mod;
            cout<<dp[i+1]<<' ';
        }
        cout<<"Case #"<<kkk+1<<": "<<dp[m-1]<<'\n';
    }

    return 0;
}