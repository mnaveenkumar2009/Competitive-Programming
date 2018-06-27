// nlogn

#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define ll long long
const ll N = 1e5;
ll n,t[2 * N],i,j,a[N];

void build() {  // build the tree
  for (ll i = n - 1; i > 0; --i) t[i] = min(t[i<<1] ,t[i<<1|1]);
}

void modify(ll p, ll value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = min(t[p], t[p^1]);
}

ll query(ll l, ll r) {  // min on interval [l, r)
  ll res = INT_MAX;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = min(res, t[l++]);
    if (r&1) res = min(res,t[--r]);
  }
  return res;
}

int main()
{
    cin>>n;
    f(i,n)t[n+i]=INT_MAX;t[2*n-1]=0;
    build();
    f(i,n)cin>>a[i];
    f(j,n-1){
        i=n-j-2;
        modify(i,query(i,min(a[i]+i+1,n))+1);
    }
    cout<<t[n];
	return 0;
}