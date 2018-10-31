#include <bits/stdc++.h>
#define ll long long
const ll N = 2e6+2;
ll n; 
ll tree[2 * N];

void build() {  // build the tree
    for (ll i = n - 1; i > 0; --i) 
        tree[i] = tree[i<<1] + tree[i<<1|1];
}

void modify(ll p, ll value) {  // set value at position p
    for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = tree[p] + tree[p^1];
}

ll query(ll l, ll r) {  // sum on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += tree[l++];
        if (r&1) res += tree[--r];
    }
    return res;
}
// tree[n+i] is a[i]