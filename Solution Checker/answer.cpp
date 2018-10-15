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
#define revsort1(a) sort(a.begin(),a.end(),greater <int>())
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
int main()
{
    ll t=sc,i,j;
    vl num2(1000006,1);
    f(i,1000006){
        if(i<2)continue;
        {
            ll xxx=((i*(i-1))/2)%mod;
            num2[i]=(num2[i-2]*((xxx*pr(i/2,mod-2))%mod))%mod;
        }
    }
    while(t--){
        ll n=sc;
        vl a,c(1000006,0);
        f(i,n){
            ll x=sc;
            if(!c[x])
                a.pb(x);
            c[x]++;
        }
        revsort1(a);
        n=a.size();
        ll ans=1;
        f(i,n-1){
            if(num2[c[a[i]]])
                ans=(ans*num2[c[a[i]]])%mod;
            if(c[a[i]]&1){
                ans=(ans*c[a[i+1]])%mod;
                c[a[i+1]]--;
            }
        }
        if(num2[c[a[n-1]]])
            ans=(ans*num2[c[a[n-1]]])%mod;
        cout<<ans<<'\n';    
    }
    return 0;
}