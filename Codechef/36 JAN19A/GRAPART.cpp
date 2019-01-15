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
inline ll uscan(){
    ll n=0,c=gc();bool check=0;
    while(c<'0'||c>'9'){if(c=='-')check=1;c=gc();}
    while(c<='9'&&c>='0'){n=n*10+c-'0';c=gc();}
    return check?-n:n;
}
#define sc uscan()

int main()
{
    ll t=sc;
    while(t--){
        ll n=sc;
        ll i,j,k;
        vl adj[n];
        set <ll> adj2[n];
        f(i,n-1){
            ll x=sc-1,y=sc-1;
            adj[x].pb(y);
            adj[y].pb(x);
            adj2[x].insert(y);
            adj2[y].insert(x);
        }
        vl u,v;
        vl bfs(1,0);
        vl lev(n);
        vl par(n,-1);
        ll level=0;
        vector <bool> vis(n,0);
        vis[0]=1;
        while(bfs.size()){
            vl newbfs;
            level++;
            for(auto it:bfs){
                lev[it]=level;
                if(level&1)
                    u.pb(it);
                else
                    v.pb(it);
                for(auto ad:adj[it]){
                    if(!vis[ad]){
                        vis[ad]=1;
                        par[ad]=it;
                        newbfs.pb(ad);
                    }
                }
            }
            bfs=newbfs;
        }
        if(u.size()<v.size()){
            level=0;
            v.erase(v.begin(),v.end());
            u.erase(u.begin(),u.end());
            bfs.erase(bfs.begin(),bfs.end());
            bfs.pb(adj[0][0]);
            f(i,n)vis[i]=0;
            f(i,n)par[i]=-1;
            vis[adj[0][0]]=1;
            while(bfs.size()){
                vl newbfs;
                level++;
                for(auto it:bfs){
                    lev[it]=level;
                    if(level&1){
                        u.pb(it);
                    }
                    else{
                        v.pb(it);
                    }
                    for(auto ad:adj[it]){
                        if(!vis[ad]){
                            vis[ad]=1;
                            par[ad]=it;
                            newbfs.pb(ad);
                        }
                    }
                }
                bfs=newbfs;
            }    
        }
        
        vl nodesinthislevel[20000];
        ll maxlev=0;
        f(i,n){
            nodesinthislevel[lev[i]].pb(i);
            maxlev=max(maxlev,lev[i]);
        }
        if(u.size()==v.size()){
            cout<<1<<'\n';
            for(auto it:u)cout<<it+1<<' ';pc('\n');
            for(auto it:v)cout<<it+1<<' ';pc('\n');
        }
        else{
            cout<<2<<'\n';
            vector <bool> canichangethis(n,1);
            u.erase(u.begin(),u.end());
            sort(v);
            for(auto it:v){
                if(adj[it].size()==1){
                    canichangethis[par[it]]=0;
                }
            }
            for(ll curlev=maxlev;curlev>=0;curlev--){
                if(curlev&1){
                    for(auto node:nodesinthislevel[curlev]){
                        // if(adj[node].size()>1&&(curlev+1)==maxlev)continue;
                        if(canichangethis[node]){
                            canichangethis[par[par[node]]]=0;
                            v.pb(node);
                            if(v.size()==n/2)break;
                        }
                    }
                }
                if(v.size()==n/2)break;
            }
            sort(v);
            f(i,n){
                if(!binary_search(v.begin(),v.end(),i))u.pb(i);
            }
            for(auto it:u)cout<<it+1<<' ';pc('\n');
            for(auto it:v)cout<<it+1<<' ';pc('\n');
        }        
    }
	return 0;
}