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
#define double long double
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
inline ll fpow(ll n, ll k) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = (r * n)% mod; n = (n * n) % mod;} return r;}

#define MAXX 300005
ll depth[MAXX],par[MAXX],subtree[MAXX],binary_lnode[MAXX][20],binary_lval[MAXX][20];
bool vis[MAXX];
vector <ll> adj[MAXX];

ll lca(ll u,ll v){
    // 
    while(depth[u]<depth[v]){
        v=par[v];
    }
    while(u!=v){
        u=par[u];
        v=par[v];
    }
    return u;
}

ll binary_lift(ll node, ll height){
    if(height==0){
        return 0;
    }
    ll logh = (ll)log2(height);
    ll possible_jump=(1<<logh);
    return binary_lift(binary_lnode[node][logh],height-possible_jump)+binary_lval[node][logh];
}
ll dfs(ll node, ll parent){
    depth[node]=depth[parent]+1;
    par[node]=parent;
    vis[node]=1;
    subtree[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            subtree[node]+=dfs(it,node);
        }
    }
    return subtree[node];
}
int main()
{
    int t=sc;
    while(t--){
        ll n=sc,q=sc;
        ll i,j,k;
        f(i,n){
            adj[i].clear();
            vis[i]=0;
            subtree[i]=0;
            depth[i]=par[i]=-1;
        }
        f(i,n-1){
            ll u=sc-1,v=sc-1;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        // root 0
        depth[0]=0;
        dfs(0,-1);
        f(i,n){
            // cout<<subtree[i]<<' '<<depth[i]<<' '<<par[i]<<'\n';
        }
        vector <ll> ignoedge(n,0),igparent(n,0),igparedge(n,0);
        f(i,n){
            ignoedge[i]=(n-1-(n-subtree[i]))*(n-subtree[i]);
            for(auto child:adj[i]){
                if(child!=par[i]){
                    ignoedge[i]+=subtree[child]*(n-1-subtree[child]);
                    igparent[i]+=subtree[child]*(subtree[i]-1-subtree[child]);
                }
            }
            ignoedge[i]/=2;
            igparent[i]/=2;
            ignoedge[i]++;// i to i
            igparent[i]++;// i to i
            ignoedge[i]+=n-subtree[i];
            for(auto child:adj[i]){
                if(child!=par[i]){
                    ignoedge[i]+=subtree[child];
                    igparent[i]+=subtree[child];
                }
            }
            for(auto child:adj[i]){
                if(child!=par[i]){
                    igparedge[child]=igparent[i]-(subtree[child]*(subtree[i]-subtree[child]));
                }
            }            
        }
        f(i,n){
            // cout<<ignoedge[i]<<' '<<igparent[i]<<' '<<igparedge[i]<<'\n';
        }
        while(q--){
            ll u=sc-1,v=sc-1;
            if(depth[u]>depth[v])swap(u,v);
            ll ans=0;
            if(u==v){
                cout<<ignoedge[u]<<'\n';
                continue;
            }
            if(par[v]==u){
                cout<<igparent[v]+ignoedge[u]-(subtree[v]*(n-subtree[v]))<<'\n';
                continue;
            }
            // cout<<lca(u,v)<<'\n';
            if(lca(u,v)==u){
                ans=igparent[v];
                while(par[v]!=u){
                    ans+=igparedge[v];
                    v=par[v];
                }
                ans+=ignoedge[u]-(subtree[v]*(n-subtree[v]));
                cout<<ans<<'\n';
                continue;
            }
            // u,v
            ans+=igparent[u]+igparent[v];
            // cout<<ans<<'\n';
            while(par[u]!=par[v]){
                if(depth[u]>depth[v]){
                    ans+=igparedge[u];
                    u=par[u];
                }
                else{
                    ans+=igparedge[v];
                    v=par[v];
                }
            }
            ll lca=par[u];
            ans+=ignoedge[lca];
            ans-=(subtree[v]*(n-subtree[v]));
            ans-=(subtree[u]*(n-subtree[v]-subtree[u]));
            //binary_lift()
            cout<<ans<<'\n';
        }
    }
    return 0;
}
