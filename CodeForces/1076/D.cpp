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
    f(i,a.size()/2){
        cout<<a[i]<<' ';
    }pc('\n');

    f(i,a.size()/2){
        cout<<a[a.size()/2+i]<<' ';
    }pc('\n');
}
void prin(ll a[],ll n){
    ll i;
    f(i,n/2){
        cout<<a[i]<<' ';
    }pc('\n');

    f(i,n/2){
        cout<<a[n/2+i]<<' ';
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
void prin(vector <pair <ll,ll> > a){
    ll i,j;
    f(i,a.size()){
            cout<<a[i].ff<<' '<<a[i].ss;
        pc('\n');
    }
    pc('\n');
}
#define inf 1e15
vl d(300006,inf),parent(300006,-1);
ll n,m,k;
vector <pair<ll,ll> > adj[300006];
vl adj2[300006];
void dijkstra(){
    ll v=0;
	d[v] = 0;
    parent[0]=-1;
	ll u;
	set<pair<ll,ll> > s;
	s.insert({d[v], v});
	while(!s.empty()){
		u = s.begin() -> second;
		s.erase(s.begin());
		for(auto p : adj[u]) //adj[v][i] = pair(vertex, weight)
			if(d[p.first] > d[u] + p.second){
                parent[p.first] = u;
				s.erase({d[p.first], p.first});
				d[p.first] = d[u] + p.second;
				s.insert({d[p.first], p.first});
			}
	}
}
vector <bool > vis(300006,0);
set <pair <ll,ll> > ans;
void prllPath(ll j){
    vis[j]=1;
    if (parent[j] == - 1)
        return;
    ans.insert(mp(min(j,parent[j]),max(j,parent[j])));
    if(!vis[parent[j]])
        prllPath(parent[j]);
} 
void prllSolution()
{
    ll j;
    for (ll i = 1; i < n; i++) 
    { 
        if(!vis[i]){
            prllPath(i);    
        }
    }
}
vector <bool > vis2(300006,0);
vl leel(300006,0);
ll maxlev=0;
ll dfs(ll node,ll level){
    maxlev=max(level,maxlev);
    vis2[node]=1;
    leel[node]=level;
    for(auto it:adj2[node]){
        if(!vis2[it]){
            dfs(it,level+1);
        }
    }
}
bool myfn(pair <ll,ll> x,pair <ll,ll> y ){
    ll lev1=max(leel[x.ff],leel[x.ss]);
    ll lev2=max(leel[y.ff],leel[y.ss]);
    return lev1<lev2;
}
ll has(ll a,ll b){
    ll sum=a+b;
    return (sum*(sum+1))/2+a;
}
int main()
{ 
    n=sc;
    m=sc,k=sc;
    ll i,j;
    map <ll,ll> inp;
    f(i,m){
        ll x=sc-1,y=sc-1,wei=sc;
        adj[x].pb(mp(y,wei));
        adj[y].pb(mp(x,wei));
        inp[has(min(x,y),max(x,y))]=i;
    }
    dijkstra();
    prllSolution();
    set <ll> finalans;
    for(auto it:ans){
        // cout<<it.ff<<' '<<it.ss<<'\n';
        adj2[it.ff].pb(it.ss);
        adj2[it.ss].pb(it.ff);
    }
    dfs(0,0);
    // cout<<maxlev<<'\n';
    // f(i,n){
    //     cout<<leel[i]<<' ';
    // }
    // pc('\n');

    vector <pair<ll,ll> > anss;
    for(auto it:ans){
        anss.pb(it);
        // cout<<it.ff<<' '<<it.ss<<'\n';
    }
    // prin(inp);
    // sort1(inp);
    sort(anss.begin(),anss.end(),myfn);
    
    while(anss.size()>k)anss.pop_back();
    for(auto it:anss){
        // cout<<it.ff<<' '<<it.ss<<'\n';
        finalans.insert(inp[has(it.ff,it.ss)]);
    }
    cout<<finalans.size()<<'\n';
    for(auto it:finalans){
        cout<<it+1<<' ';
    }
    return 0;
}