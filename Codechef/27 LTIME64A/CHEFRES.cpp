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


int main()
{
    // ios::sync_with_stdio(0);
    ll t=sc,iiii;
    f(iiii,t){
        ll i,j,k;
        ll n=sc,m=sc;ll p[m];
        vector <pair <ll,ll> > tim(n);
        f(i,n){
            tim[i].ff=sc;
            tim[i].ss=sc;
        }
        ll r[n];
        sort1(tim);
        f(i,n)r[i]=tim[i].ss;
        f(i,m){
            p[i]=sc;
            ll ans=upper_bound(r,r+n,p[i])-r;
            if(ans==n)cout<<"-1\n";
            else{
                ans=tim[ans].ff-p[i];
                ans=max(ans,(ll)0);
                cout<<ans<<'\n';
            }
        }
    }
    return 0;
}