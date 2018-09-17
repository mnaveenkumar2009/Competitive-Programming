#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define f(i,n) for(i=0;i<n;i++)
#define sc uscan()
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

#define N 300007
ll t[2 * N];
ll n,k;

void build() {  // build the tree
  for (ll i = n - 1; i > 0; --i) t[i] = min( t[i<<1] ,t[i<<1|1]);
}

ll query(ll l, ll r) {  // sum on interval [l, r)
  ll res = 1e14;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res,t[l++]);
    if (r&1) res = min(res,t[--r]);
  }
  return res;
}

int main() {
    ll tt;
    // t=sc;
    tt=1;
    ll kkk=0;
    // ios_base::sync_with_stdio(0);
    f(kkk,tt){
        n=sc,k=sc;
        vector <ll> a(n);
        ll i,j;
        f(i,n){
            a[i]=sc;
        }
        sort(a.begin(),a.end());

        ll b[n]={0};
        f(i,n-k+1){
            b[i]=t[n + i]=abs(a[i]-a[i+k-1]);
        }
        f(i,n){
            if(i>=n-k+1)
                t[n+i]=b[i]=b[i-1];
        }
        build();

        ll ans=0;
        ll c[n];
        // f(i,n-k+1){
        //     cout<<b[i]<<' ';
        // }pc('\n');

        f(i,n){
            ll l=max(i+1-k,(ll)0),r=i;
            c[i]=query(l,r+1);
        }
        // f(i,n)cout<<c[i]<<' ';pc('\n');
        f(i,n){
            ans=max(ans,c[i]);
        }
        cout<<ans;
    }
    return 0;
}