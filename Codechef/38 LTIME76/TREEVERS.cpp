#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
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
void prin(vector <ll> a){
    for(auto it:a)cout<<it<<' ';pc('\n');
}
void prin(vector <vector <ll> > a){
    for(auto vec:a){for(auto it:vec)cout<<it<<' ';pc('\n');}pc('\n');
}
void prin(vector <pair <ll,ll> > a){
    for(auto it:a)cout<<it.ff<<' '<<it.ss<<'\n';pc('\n');
}
#define MAXN 100006
vector <ll> adj[MAXN];
vector <bool> vis(MAXN);
vector <ll> w(MAXN), par(MAXN), N1(MAXN), S(MAXN);
vector <ll> fans;
pair <ll, ll> dfs(ll node, ll parent){
    par[node] = parent;
    vis[node] = 1;
    N1[node] = w[node];
    S[node] = 1;
    for(auto child : adj[node]){
        if(!vis[child]){
            pair <ll, ll> dfsval = dfs(child, node);
            S[node] += dfsval.ff;
            N1[node] += dfsval.ss;
        }
    }
    return mp(S[node], N1[node]);
}

void dfs2(ll node){
    // cout<<node<<'\n';
    vis[node] = 1;
    fans.push_back(node);
    vector < pair <ld, ll> > children;
    for(auto child : adj[node]){
        if(!vis[child]){
            ld sec = (ld)N1[child]/(ld)(S[child] - N1[child]);
            children.push_back({sec, child});
        }
    }
    sort(children);
    for(auto child : children){
        // if(!vis[child.ss])
            dfs2(child.ss);
    }
}
int main() {
    ll t = sc;
    while(t--){
        fans.clear();
        ll n = sc, no0 = 0;
        f(i,n){
            w[i] = sc;
            if(w[i] == 0){
                no0++;
            }
            adj[i].clear();
            vis[i] = 0;
            N1[i] = S[i] = 0;
        }
        f(i, n - 1){
            ll u = sc - 1, v = sc - 1;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(0, -1);
        f(i,n){
            // cout<<par[i] << ' '<<N1[i] << ' '<< S[i]<<'\n';
        }
        f(i, n)
            vis[i] = 0;
        dfs2(0);
        ll ans = 0;
        // cout<<no0<<'\n';
        for(auto node: fans){
            // cout<<node<<' ';
            if(w[node]){
                ans += no0;
            }
            else{
                no0--;
            }
        }
        cout << ans<<'\n';
    }
	return 0;
}