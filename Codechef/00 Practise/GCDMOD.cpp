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

void disp(ll arr[],ll n){
    ll i;
    f(i,n){
        cout<<arr[i]<<' ';
    }pc('\n');
}

ll mul(ll x, ll y, ll m){
    ll res = 0; 

    x = x % m;

    while (y > 0)
    {
        if (y & 1)
            res = (res+x) % m;

        y = y>>1; // y = y/2
        x = (2*x) % m;  
    }
    return res;
}
ll pr(ll x, ll y, ll m)
{
    ll res = 1; 

    x = x % m;

    while (y > 0)
    {
        if (y & 1)
            res = mul(res,x,m);

        y = y>>1; // y = y/2
        x = mul(x,x,m);
    }
    return res;
}
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int main()
{
    ll kkk,t=uscan();
    f(kkk,t){
        ll a=uscan(),b=uscan(),n=uscan();
        if(a==b){
            cout<<(2*pr(a,n,mod))%mod<<'\n';
            continue;
        }
        ll dif=abs(a-b);
        ll temp=pr(a,n,abs(a-b))+pr(b,n,abs(a-b));
        if(!temp){
            cout<<abs(a-b)%mod<<'\n';
            continue;
        }
        cout<<gcd(temp,dif)%mod<<'\n';
    }
    return 0;
}