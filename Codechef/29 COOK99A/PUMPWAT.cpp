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
void prin(ll a[],ll n){
    ll i;
    f(i,n){
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
#define vl vector <ll> 
#define vvl vector <vector <ll> >

#define ll long long
const ll N = 1e5+6;
ll n; 
ll t[2 * N];
unordered_map <ll,ll> pos;
void build() {  // build the tree
    // cout<<"build";
    for (ll i = n - 1; i > 0; --i) t[i] = max(t[i<<1] , t[i<<1|1]);
}

ll query(ll l, ll r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res =max(res,t[l++]);
      if (r&1) res = max(t[--r],res);
    }
    return res;
}

ll f2(ll l, ll r){
    ll posi=query(l,r+1);
    posi=pos[posi];
    // cout<<l<<' '<<r<<' '<<posi<<'\n';
    if(posi==l||posi==r)return 1;

    return 1+min(f2(l,posi-1),f2(posi+1,r));
}
int main()
{
    ll tt=sc,kkk;
    f(kkk,tt){
        n=sc;
        ll i,j,k;
        f(i,n){
            ll x=sc;
            pos[x]=i;
            // cout<<x<<'\n';
            t[n+i]=x;
            // cout<<x<<'\n';
        }
        // cout<<"sdf";
        build();
        // cout<<"bef";
        cout<<f2(0,n-1)<<'\n';
    }
    return 0;
}