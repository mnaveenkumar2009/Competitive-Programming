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
    ll t=uscan();
    while(t--){
        ll x1=uscan(),y1=uscan(),x2=uscan(),y2=uscan(),x3=uscan(),y3=uscan();
        ll a=gc(x1,y1,x2,y2);
        ll b=gc(x3,y3,x2,y2);
        ll c=gc(x1,y1,x3,y3);
        ll tot =a+b+c+3;
        cout<<((nc3(tot)-nc3(a+2)-nc3(b+2)-nc3(c+2))%mod+mod)%mod<<'\n';        
    }
    return 0;
}