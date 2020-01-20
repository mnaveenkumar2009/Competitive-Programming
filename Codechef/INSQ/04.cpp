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
#define sort(a) sort(a.begin(),a.end())
#define sortn(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>

        ll ans = 0;
inline ll uscan(){
    ll n=0,c=gc();bool check=0;
    while(c<'0'||c>'9'){if(c=='-')check=1;c=gc();}
    while(c<='9'&&c>='0'){n=n*10+c-'0';c=gc();}
    return check?-n:n;
}
#define sc uscan()
void prin(vector <ll> a){
    for(auto it:a)cout<<it<<' ';pc('\n');
}
void prin(vector <vector <ll> > a){
    for(auto vec:a){for(auto it:vec)cout<<it<<' ';pc('\n');}pc('\n');
}
void prin(vector <pair <ll,ll> > a){
    for(auto it:a)cout<<it.ff<<' '<<it.ss<<'\n';pc('\n');
}


int n;
vector <ll> adj[100005];
vector <bool> vis(100005,0LL);
vl a(100005,0LL);

vector <pair <ll,pair <ll,ll> > > dp(100005);
pair <ll,pair <ll,ll> > dfs(ll node){
    // cout<<node<<'\n';
    if(dp[node].ff != -1e15)
        return dp[node];
    pair <ll,pair <ll,ll> > ret = {0,{a[node],a[node]}},chl,chr;
    vis[node] = 1;

    // {2,{1,0LL}} 
    // 2 - cur 0
    // 1 - subtree has a 0
    set < pair <ll,pair <ll,ll> > > children;
    for(auto child: adj[node]){
        if(!vis[child]){
            children.insert(dfs(child));
        }
    }
    if(children.size()==0){
        return dp[node] = ret;
    }
    set < pair <ll,pair <ll,ll> > > :: iterator it = children.end();
    it--;
    if(children.size()==1){
        ret.ff += max(max((*it).ff,(*it).ss.ss),0LL); // 2
        ret.ss.ff += max(max((*it).ff,(*it).ss.ff),0LL);
        ret.ss.ss += max((*it).ss.ss,0LL);
        return dp[node] = ret;
    }
    ll max0l=0,max1l=0,max2l=0,max0r=0,max1r=0,max2r=0;
    vl max0,max1,max2;
    for(auto child:children){
        
    }
    ll a22 = max(max2l,0LL) + max(max2r,0LL);
    ll a02 = max(max0l,0LL) + max(max2r,0LL);
    ll a20 = max(max2l,0LL) + max(max0r,0LL);
    ll a00 = max(max0l,0LL) + max(max0r,0LL);
    ll a01 = max(max0l,0LL) + max(max1r,0LL);
    ll a10 = max(max1l,0LL) + max(max0r,0LL);
    if(node == 3){
        // cout<<a00<<'\n';
    }
    ret.ff += max(max0l,max(max2l,0LL));
    ret.ss.ss += max(max0l,0LL);
    ret.ss.ff += max(max(max0l,max1l),max(max2l,0LL));
    ans = max(max(max(a22,a00),max(a20,a02)),ans);
    ans = max(ans, a[node] + max(a00,max(a10,max(a20,max(a02,max(a01,0LL))))));
    dp[node] = ret;

    return dp[node];
}
int main(){
    int t=sc;
    while(t--){
        ans = 0;
        n=sc;
        ll i;
        f(i,n){
            a[i]=sc;
            // cout<<a[i]<<' ';
            vis[i]=0;
            adj[i].clear();
            dp[i] = {-1e15,{0,0LL}};
        }
        f(i,n-1){
            ll u=sc-1,v=sc-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0);
        f(i,n){
            // cout<<dp[i].ss.ss<<' '<<dp[i].ss.ff<<' '<<dp[i].ff<<'\n';
            ans = max(ans,max(dp[i].ss.ss,max(dp[i].ss.ff,dp[i].ff)));
        }
        cout<<ans<<'\n';
    }
}