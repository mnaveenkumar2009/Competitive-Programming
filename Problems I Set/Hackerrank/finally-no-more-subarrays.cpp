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
void prin(vector <ll> a){
    ll i;
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}
#define sc uscan()
#define gcd __gcd
#define bpc __builtin_popcountll
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
const ll N = 2e6+9;
ll n; 
ll tree[2 * N];

void build() {  // build the tree
    for (ll i = n - 1; i > 0; --i) 
        tree[i] = (tree[i<<1] + tree[i<<1|1]);
}

void modify(ll p, ll value) {  // set value at position p
    for (tree[p += n] = value; p > 1; p >>= 1) 
    tree[p>>1] = (tree[p] + tree[p^1]);
}

ll query(ll l, ll r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = (res+tree[l++])%mod;
        if (r&1) res = (res+tree[--r])%mod;
    }
    return res;
}

ll kthmin(ll k,ll l,ll r) {
    // cout<<"kth"<<k<<' '<<l<<' '<<r<<'\n';
    if(l==r)
        return l;
    ll mid=(l+r)/2;
    ll tem=query(l,mid+1);
    // cout<<tem<<'\n';
    if(tem>=k){
        return kthmin(k,l,mid);
    }
    else{
        k-=tem;
        return kthmin(k,mid+1,r);
    }
}
int main(){
    n=1e6+2;
    ll N=sc;
    ll q=sc;

    vl a(N);
    ll i,j,k;
    f(i,N){
        a[i]=sc;
        modify(a[i],query(a[i],a[i]+1)+1);
    }
    while(q--){
        if(sc==1){
            ll k=sc;
            cout<<kthmin(k,0,n-1)<<'\n';
        }
        else{
            ll x=sc-1,y=sc;
            modify(a[x],query(a[x],a[x]+1)-1);
            a[x]=y;
            modify(y,query(y,y+1)+1);
        }
    }
}