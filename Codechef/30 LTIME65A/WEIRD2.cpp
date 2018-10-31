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

#include <bits/stdc++.h>
#define ll long long
const ll N = 1e6+5;
ll n; 
ll t[2 * N];

void build() {  // build the tree
    for (ll i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(ll p, ll value) {  // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ll query(ll l, ll r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += t[l++];
      if (r&1) res += t[--r];
    }
    return res;
}

int main()
{
    ll tt=sc,kkk;

    f(kkk,tt){
        n=sc;
        ll i,j;
        vector <ll> a(n);
        vector <ll> c(1000006,0);
        vector <bool> done(1000006,0);
        f(i,n){
            a[i]=sc;
            c[a[i]]++;
        }
        sort1(a);
        set <pair <ll,ll> > b;
        f(i,n){
            b.insert(mp(c[a[i]],a[i]));
        }
        f(i,n){
            if(c[i])
                t[n+i]=1;
            else{
                t[n+i]=0;
            }
        }
        build();
        // f(i,n){
        //     cout<<query(i,i+1)<<' ';
        // }pc('\n');
        ll ans=0;
        f(i,n){
            if(done[a[i]])continue;
            done[a[i]]=1;

            // cout<<i<<'\n';
            for(auto it:b){
                // cout<<it.ff<<' '<<it.ss<<'\n';
                if(it.ff<a[i]){
                    modify(it.ss,0);
                    b.erase(it);
                }
                else{
                    break;
                }
            }
            // cout<<ans<<'\n';
            ans+=query(1,c[a[i]]+1);
            if(c[a[i]]>=a[i]){
                ans;
            }
            // cout<<ans<<'\n';
        }
        cout<<ans<<'\n';
    }

    return 0;
}