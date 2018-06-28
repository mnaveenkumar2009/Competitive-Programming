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
#define NIL -1
inline ll uscan()
{
    ll n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
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

int main()
{
    ll n=uscan(),k=uscan(),i;
    vector <ll> pos(2000);
    bool b[109]={0},we=1;
    f(i,n){
        ll x=uscan();
        b[x]=1;
        pos[x]=i;
    }
    vector <ll> ans;
    f(i,109){
        if(b[i])ans.pb(i);
    }
    if(ans.size()<k)we=0;
    if(we){
        cout<<"YES\n";
        f(i,k)cout<<pos[ans[i]]+1<<' ';
    }
    else
    cout<<"NO\n";
	return 0;
}