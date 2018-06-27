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
ll n,i,j,m;
ll dist()
int main()
{
    m=uscan();
    n=uscan();
    vector <pair <ll,ll> > a(n);
    f(i,n){
        a[i].ff=uscan();
        a[i].ss=uscan();
    }
    ll low=0,high=m/2,mid;
    while(low!=high){
        bool we=1;
        mid=(high+low)/2;
        vector <ll> b;
        b.pb(a[0].ff);
        ll mx=a[0].ff;
        for(int i=1;i<n;i++){
            if(mx+mid<a[i].ff){
                we=0;
            }
            b.pb(min(a[i].ss,mx+mid));
        }


        if(we){//poss
            low=mid;
        }
        else{
            high=mid-1;
        }
    }
    cout<<low<<'\n';
	return 0;
}