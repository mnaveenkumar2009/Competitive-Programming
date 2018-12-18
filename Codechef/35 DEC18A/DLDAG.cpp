#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll int
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


vector <int> ado[1000006],adi[1000005];
vector <bool> vis(1000006);
void TS(int node,vector <int> &stak){
    vis[node] = 1;
    vector <ll> tem;
    for (auto i:ado[node]) 
        if (!vis[i])
            tem.pb(i);
    random_shuffle ( tem.begin(), tem.end() );
    
    for(auto i:tem){
        if(!vis[i])
        TS(i,stak);
    }
    stak.pb(node);
}
long long has(ll x,ll y){
    long long sum=(x+y);
    sum*=sum+1;
    sum>>=1;
    return sum+min(x,y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unordered_map<ll,bool> xxx;
    ll n=sc,m=sc,i;
    while(m--){
        ll x=sc-1,y=sc-1;
        ado[x].pb(y);
        xxx[has(x,y)]=1;
        // adi[y].pb(x);
    }
    ll finans=INT_MAX;
    vector <ll> finprin;
    ll numberoftime=5;
    while(numberoftime--){
        // cout<<numberoftime<<'\n';
        fill(vis.begin(), vis.end(), 0);
        vector <ll> prin;
        int ccc=0;
        int amistuckherefortoolong=0;
        vector <int> stak;
        for(int i=0;i<n;i++)
            if(!vis[i])
                TS(i,stak);
        // cout<<stak.size()<<'\n';
        // for(auto it:stak){
        //     cout<<it<<' ';
        // }cout<<('\n');
        // }
        int ffff=10;
        while(ffff--)
        for(int i=0;i<n-2;i++){
            if(xxx[has(stak[i],stak[i+1])]){
                if(!xxx[has(stak[i+1],stak[i+2])]){
                    swap(stak[i+1],stak[i+2]);
                }
            }
        }
        for(int i=0;i<n;i++){
            // cout<<stak[i]<<' ';
            // cout<<i<<'\n';
            bool we=0;
            if(i!=n-1){
                if(!xxx[has(stak[i],stak[i+1])]){
                    we=1;
                }
            }
            if(we){
                ccc++;
                prin.pb(2);
                prin.pb(stak[i]+1);
                prin.pb(stak[++i]+1);
            }
            else{
                ccc++;
                prin.pb(1);
                prin.pb(stak[i]+1);
            }
        }
        // pc('\n');
        if(ccc<finans){
            finans=ccc;
            finprin=prin;
        }
    }
    // return 0;
    cout<<finans;
    ll xxxx=0;
    for(auto it:finprin){
        if(!xxxx){
            cout<<'\n';
            xxxx+=it+1;
        }
        cout<<it<<' ';
        xxxx--;
    }
	return 0;
}