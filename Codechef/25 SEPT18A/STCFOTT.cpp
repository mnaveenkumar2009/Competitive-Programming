#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
// #define mod 1000000007
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

vector <ll> adj[250];
bool vis[250];
ll par[250],depth[250];
ll ans[250],t[250];
ll edges[250*250][2];
// exp at node i

void dfs(ll node,ll parent){
    vis[node]=1;
    par[node]=parent;
    // depth[node]=dep;
    // path.pb(node);
    for(int i=0;i<adj[node].size();i++){
        if(!vis[adj[node][i]]){
            dfs(adj[node][i],node);
        }
    }
}
ll por[250];
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
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    vector <ll> branches;
    ll n=sc,i;
    f(i,250)por[i]=pr(i,mod-2);
    f(i,n-1){
        ll u=sc-1,v=sc-1;
        if(u>v){
            swap(u,v);
        }
        branches.pb(u*250+v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0,-1);
    // cout<<"par\n";
    // f(i,n)cout<<par[i]<<' ';cout<<'\n';
    ll m=sc;
    // ll t[m];
    ll enter[1100000]={0};
    f(i,m){
        t[i]=sc;
        if(t[i]<1e6+1e5)
            enter[t[i]]++;
    }
    ll q=sc;
    // ll cans[250]={0};
    ll edges[2][100000][2];// 0 is u to v, 1 is v to 1 .. u= index/250, v=index%250
    memset(edges,0,sizeof(edges));
    for(ll sec=1;sec<=q;sec++){
        ll i;
        if(enter[sec]){
            // update edge
            // cout<<"new\n";
            ll upd=por[adj[0].size()];
            for(auto node:adj[0]){
                // cout<<node<<'\n';
                edges[sec&1][node][0]=(edges[sec&1][node][0]+upd)%mod;
            }
        }
        f(i,n-1){
            ll edg=branches[i];
            // if(edg==252){
            //     cout<<edges[1][252][0]<<' '<<edges[0][252][0]<<"x\n";
            // }
            ll u=edg/250,v=edg%250;
            edges[(sec+1)&1][edg][0]=0;
            edges[(sec+1)&1][edg][1]=0;
            // cout<<u<<' '<<v<<' '<<ans[u]<<' '<<ans[v]<<'\n';
            ans[u]=(ans[u]+edges[sec&1][edg][0])%mod;// u to v
            ans[v]=(ans[v]+edges[sec&1][edg][1])%mod;
        }
        // f(i,n)
        //     cout<<(ans[i]+(ll)mod)%mod<<' ';pc('\n');
        // memset(edges[(sec+1)&1],0,sizeof(edges[(sec+1)&1]));
        // 1 0     0 1
        f(i,n-1){
            //change directions
            ll edg=branches[i];
            ll u=edg/250,v=edg%250;
            if(!u){
                if(adj[v].size()==1){
                    // cout<<"root and leaf";
                    edges[(sec+1)&1][edg][1]=(edges[sec&1][edg][0]+edges[(sec+1)&1][edg][1])%mod;
                    ll upd=(por[adj[u].size()]*edges[sec&1][edg][1])%mod;
                    if(upd)
                    for(auto it:adj[u]){
                        edges[(sec+1)&1][it][0]=(upd+edges[(sec+1)&1][it][0])%mod;
                    }
                }
                else
                {// root and not leaf child
                    ll upd=(por[adj[u].size()]*edges[sec&1][edg][1])%mod;
                    if(upd)
                    for(auto it:adj[u]){
                        edges[(sec+1)&1][it][0]=(upd+edges[(sec+1)&1][it][0])%mod;
                    }
                    upd=(por[adj[v].size()-1]*edges[sec&1][edg][0])%mod;
                    if(upd)
                    for(auto it:adj[v]){
                        // v to it's edges
                        if(it){
                            // cout<<upd<<' '<<it<<' '<<v<<'\n';
                            if(it<v)
                                edges[(sec+1)&1][it*250+v][1]=(edges[(sec+1)&1][it*250+v][1]+upd)%mod;
                            else{
                                edges[(sec+1)&1][v*250+it][0]=(edges[(sec+1)&1][v*250+it][0]+upd)%mod;
                            }
                        }
                    }
                }
            }
            else
            {
                if(adj[u].size()==1&&u){
                    // u is leaf
                    edges[(sec+1)&1][edg][0]=(edges[sec&1][edg][1]+edges[(sec+1)&1][edg][0])%mod;
                    
                    // v to par[v]
                    if(par[v]>v){
                        edges[(sec+1)&1][v*250+par[v]][0]=(edges[sec&1][edg][0]+edges[(sec+1)&1][v*250+par[v]][0])%mod;
                    }
                    else{
                        edges[(sec+1)&1][par[v]*250+v][1]=(edges[sec&1][edg][0]+edges[(sec+1)&1][par[v]*250+v][1])%mod;
                    }
                }
                // cout<<edges[1][252][0]<<' '<<edges[0][252][0]<<' '<<sec<<"x\n";
                else{
                    if(adj[v].size()==1){
                        // v is leaf
                        edges[(sec+1)&1][edg][1]=(edges[sec&1][edg][0]+edges[(sec+1)&1][edg][1])%mod;
                        
                        // u to par[u]
                        if(par[u]>u){
                            edges[(sec+1)&1][u*250+par[u]][0]=(edges[sec&1][edg][1]+edges[(sec+1)&1][u*250+par[u]][0])%mod;
                        }
                        else{
                            edges[(sec+1)&1][par[u]*250+u][1]=(edges[sec&1][edg][1]+edges[(sec+1)&1][par[u]*250+u][1])%mod;
                        }
                    }
                    else{
                        if(par[u]==v){
                            ll upd=(por[adj[u].size()-1]*edges[sec&1][edg][1])%mod;
                            if(upd)
                            for(auto it:adj[u]){
                                if(it!=v){
                                    // v to it
                                    if(it<u)
                                        edges[(sec+1)&1][it*250+u][1]=(upd+edges[(sec+1)&1][u+250*it][1])%mod;
                                    else
                                        edges[(sec+1)&1][u*250+it][0]=(upd+edges[(sec+1)&1][u*250+it][0])%mod;
                                        
                                }
                            }
                            // v to par[v]
                            upd=edges[sec&1][edg][0];
                            if(upd)
                            if(par[v]>v){
                                edges[(sec+1)&1][v*250+par[v]][0]=(upd+edges[(sec+1)&1][v*250+par[v]][0])%mod;
                            }
                            else{
                                edges[(sec+1)&1][par[v]*250+v][1]=(upd+edges[(sec+1)&1][par[v]*250+v][1])%mod;
                            }
                        }
                        else
                        {
                            ll upd=(por[adj[v].size()-1]*edges[sec&1][edg][0])%mod;
                            if(upd)
                            for(auto it:adj[v]){
                                if(it!=u){
                                    // v to it
                                    if(it<v)
                                        edges[(sec+1)&1][it*250+v][1]=(upd+edges[(sec+1)&1][v+250*it][1])%mod;
                                    else
                                        edges[(sec+1)&1][v*250+it][0]=(upd+edges[(sec+1)&1][v*250+it][0])%mod;
                                        
                                }
                            }
                            // u to par[u]
                            upd=edges[sec&1][edg][1];
                            if(upd)
                            if(par[u]>u){
                                edges[(sec+1)&1][u*250+par[u]][0]=(upd+edges[(sec+1)&1][u*250+par[u]][0])%mod;
                            }
                            else{
                                edges[(sec+1)&1][par[u]*250+u][1]=(upd+edges[(sec+1)&1][par[u]*250+u][1])%mod;
                            }
                        }
                    }
                }
            }
        }
    }

    f(i,n)
        cout<<(ans[i]+(ll)mod)%mod<<' ';
    return 0;
}