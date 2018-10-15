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
void prin(vector < pair<ll,ll> > a){
    ll i,j;
    f(i,a.size()){
        cout<<a[i].ff<<' '<<a[i].ss<<'\n';
    }
    pc('\n');
}

vector<vector<ll> > floydWarshall(vector<vector<ll> > G)  {
    ll n = G.size();
    //For all edges (i, j), G[i][j] = length of the edge, infinity otherwise
    //G[i][i] = 0 for all i
    for(ll k=0; k<n; k++)  {
        for(ll i=0; i<n; i++)  {
            for(ll j=0; j<n; j++)  {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    return G;
}
int main()
{
    ll t=sc,kkk;
    f(kkk,t){
        ll ans=0;
        ll n=sc,m=sc;
        ll i,j,k;
        vector <vector <ll> > G(n,vector <ll> (n,INT_MAX));
        f(i,m){
            ll u=sc-1,v=sc-1,k=sc;
            G[u][v]=k;
            G[v][u]=k;
        }
        G=floydWarshall(G);
        vector <ll> sums;
        ll mask;
        f(mask,(1<<n)-1){
            if(mask==0)continue;
            ll tot=0;
            f(i,n){
                ll dist=INT_MAX;
                bool xi=(mask&(1<<i))>0;
                f(j,n){
                    bool xj=(mask&(1<<j))>0;
                    if(i!=j){
                        if(xi!=xj){
                            dist=min(dist,G[i][j]);
                        }
                    }
                }
                tot+=dist;
            }
            sums.pb(tot);
        }
        sort1(sums);
        // f(i,sums.size())cout<<sums[i]<<' ';
        ans=1;
        f(i,sums.size()-1){
            // cout<<sums[i]<<' ';
            if(sums[i+1]==sums[i])ans++;
            else
            break;
        }
        cout<<"Case #"<<kkk+1<<": "<<ans<<'\n';
    }
    return 0;
}