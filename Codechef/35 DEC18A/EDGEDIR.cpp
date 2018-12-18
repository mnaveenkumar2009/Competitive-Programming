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
ll maxlev=0;
vector <ll> level(100005,-1),par(100005,-1);
vector <ll> adj[100005];
vector <short> parity(100005,0);
void dfs(ll node, ll lev){
    level[node]=lev;
    maxlev=max(maxlev,lev);
    // cout<<node<<'\n';
    for(auto it:adj[node]){
        // cout<<it<<'\n';
        if(level[it]==-1){
            par[it]=node;
            dfs(it,lev+1);
        }
    }
}
ll has(ll i,ll j){
    ll sum= i+j;
    sum*=sum+1;
    sum/=2;
    return sum+min(i,j);
}

int main()
{
    ll t=sc;
    while(t--){
        ll n=sc,m=sc;
        unordered_map<ll,ll> xxx;
        ll i,j,k;
        maxlev=0;
        f(i,n){
            par[i]=-1;
            parity[i]=0;
            level[i]=-1;
            adj[i].erase(adj[i].begin(),adj[i].end());
        }
        vector <pair <ll,ll> > edges(m);
        vl ans(m,0);
        f(i,m){
            edges[i].ff=sc-1;
            edges[i].ss=sc-1;
            xxx[has(edges[i].ff,edges[i].ss)]=i;
            adj[edges[i].ff].pb(edges[i].ss);
            adj[edges[i].ss].pb(edges[i].ff);
        }
        dfs(0,0);
        // f(i,n)cout<<level[i]<<' ';cout<<'\n';
        // f(i,n)cout<<par[i]<<' ';cout<<'\n';
        vector<ll> nodes[maxlev+2];
        f(i,n){
            nodes[level[i]].pb(i);
        }
        f(i,m){
            // cout<<edges[i].ff<<' '<<edges[i].ss<<'\n';
            if(level[edges[i].ff]==level[edges[i].ss]){
                //keep 0
                parity[edges[i].ss]^=1;
            }
            else{
                if(level[edges[i].ff]<level[edges[i].ss]){
                    //first to second 
                    parity[edges[i].ss]^=1;
                }
                else{
                    // sec to first
                    ans[i]=1;
                    parity[edges[i].ff]^=1;
                }
            }
        }
        // f(i,m)cout<<ans[i]<<' ';cout<<'\n';
        // f(i,n)cout<<parity[i]<<' ';cout<<'\n';
        // return 0;
        while(maxlev){
            for(auto it:nodes[maxlev]){
                // cout<<it<<' ';
                if(parity[it]){
                    // cout<<it<<' '<<par[it]<<'\n';
                    parity[it]=0;
                    parity[par[it]]^=1;
                    ans[xxx[has(it,par[it])]]^=1;
                    // cout<<has(it,par[it])<<'\n';
                }
                // cout<<'\n';
            }
            maxlev--;
        }
        if(parity[0])
            cout<<"-1\n";
        else{
            f(i,m){
                cout<<ans[i]<<' ';
            }cout<<'\n';
        }
    }
	return 0;
}