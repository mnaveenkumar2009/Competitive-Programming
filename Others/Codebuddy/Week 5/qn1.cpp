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
int main()
{
    int n=uscan();
    ll i,j,a[n];
    f(i,n)a[i]=uscan();
    sort(a,a+n);
    ll s=uscan(),ans=a[0]+a[1]+a[2];
    vector <pair<ll,pair<ll,ll> > > temp;
    f(i,n){
        f(j,n){
            if(j-i&&j>i)
            temp.pb(mp(a[i]+a[j],mp(i,j)));
        }
    }
    
    f(j,2)
    f(i,temp.size()){
        ll xxx=lower_bound(a,a+n,(s-temp[i].ff)*(2*j-1))-a;
        if(xxx==n)xxx--;
        // cout<<temp[i].ff<<' '<<xxx<<' '<<a[xxx]<<'\n';
        if(xxx!=temp[i].ss.ff&&xxx!=temp[i].ss.ss&&xxx>=0){
            if(abs(ans-s)>abs(s-(a[xxx]+temp[i].ff) )){
                ans=(a[xxx]+temp[i].ff);
            }
        }
        xxx--;
        if(xxx!=temp[i].ss.ff&&xxx!=temp[i].ss.ss&&xxx>=0){
            if(abs(ans-s)>abs(s-(a[xxx]+temp[i].ff) )){
                ans=(a[xxx]+temp[i].ff);
            }
        }
    }
    
    cout<<ans;
	return 0;
} 