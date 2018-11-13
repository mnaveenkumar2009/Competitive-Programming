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
#define vvl vector <vector <ll> >
#define vl vector <ll>
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
set <ll> adj[200005];
set <ll> vis;
ll com;
void dfs(ll i){
    com++;
    for(auto it:vis){
        if(adj[i].find(it)==adj[i].end()){
            vis.erase(it);
            dfs(it);
        }
    }
}
int main()
{
    ll n=sc,m=sc,i,j,k;
    while(m--){
        ll x=sc-1,y=sc-1;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    f(i,n)
        vis.insert(i);
    
    vector <ll> ans;
    f(i,n){
        com=0;
        if(vis.find(i)!=vis.end()){
            vis.erase(i);
            dfs(i);
            ans.pb(com);
        }
    }
    sort1(ans);
    cout<<ans.size()<<'\n';
    for(auto it:ans){
        cout<<it<<' ';
    }
    return 0;
}
