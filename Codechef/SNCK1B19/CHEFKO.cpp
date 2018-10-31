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
#define vpl vector <pair <ll,ll> >

const ll N = 3e5;
ll n;
ll t[2 * N];

void modify(ll p, ll value) {
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p>>1] = (t[p] + t[p^1]);
}

ll query(ll l, ll r) {  // sum on interval [l, r)
    // ll res = 1e18;
    ll res=0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) 
        res = (res+t[l++]);
      if (r&1) 
        res = (res+t[--r]);
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
int main()
{
    ll tt=sc,kkk;
    f(kkk,tt){
        unordered_map <ll,ll> coml,comr;
        n=sc;
        ll k=sc;
        ll i,j;
        vector <pair <ll,ll> > a(n),b(n);
        set <ll> lefts,rights;
        f(i,n){
            a[i].ff=sc;
            a[i].ss=sc;
            lefts.insert(a[i].ff);
            rights.insert(a[i].ss);
            b[i].ff=a[i].ss;
            b[i].ss=a[i].ff;
        }
        vl lef,rig;
        for(auto it:lefts){
            // cout<<it<<' ';
            lef.pb(it);
        }
        // pc('\n');
        for(auto it:rights){
            rig.pb(it);
            // cout<<it<<' ';
        }
        // pc('\n');
        f(i,lef.size()){
            coml[lef[i]]=i;
        }
        f(i,rig.size()){
            comr[rig[i]]=i;
        }
        ll ans=0;
        sort1(a);
        sort1(b);
        f(i,n){
            swap(b[i].ff,b[i].ss);
        }
        f(i,2*n){
            t[i]=0;
        }
        f(i,n){
            ll pos=coml[b[i].ff];
            modify(pos,1+query(pos,pos+1));
        }

        f(i,n-k+1){
            //b[i].ss is r
            // ans=max(ans,kthmin(k,0,lef.size()-1));
            // cout<<kthmin(k,0,n-1)<<'\n';
            ans=max(ans,b[i].ss-lef[kthmin(k,0,lef.size()-1)]);
            ll pos=coml[b[i].ff];
            // f(j,lef.size()){
            //     cout<<query(j,j+1)<<' ';
            // }pc('\n');
            modify(pos,query(pos,pos+1)-1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}