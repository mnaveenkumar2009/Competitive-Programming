#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 998244353 
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
    f(i,a.size()){
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
void prin(vector <vector <pair <ll,ll> > > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j].ss<<' ';
        pc('\n');
    }
    pc('\n');
}
vector <ll> adj[10004];
int main()
{
    ll n=sc;
    ll i,j,k;
    f(i,n-1){
        ll x=sc-1,y=sc-1;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    ll r=sc-1,K=sc;
    vector <vector <ll> > ans(n,vl(K+1,0));
    ans[r][0]=1;
    f(k,K+1){
        if(k==0)continue;
        f(i,n){
            for(auto it:adj[i]){
                ans[i][k]=(ans[i][k]+ans[it][k-1])%mod;
            }
            cout<<ans[i][k]<<' ';
        }
        pc('\n');
    }
    f(i,n){
        cout<<ans[i][K]<<' ';
    }
    return 0;
}