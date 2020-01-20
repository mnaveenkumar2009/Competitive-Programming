#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const ll N = 3e5;
ll n;
ll t[2 * N];

void modify(ll p, ll value) {
    for (t[p += n] = value; p > 1; p >>= 1)
        t[p>>1] = (t[p] + t[p^1]);
}

ll query(ll l, ll r) {
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
signed main(){
	int m;
	cin >> n;
	pair <int, int> a[n];
	int b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = -i;
		b[i] = a[i].first;
	}
	sort(a, a + n);
	// for(int i = 0; i < n; i++){
	// 	// cout << a[i].first <<' ' << a[i].second << '\n';
	// 	modify(i, -a[i].second);
	// }
	cin >> m;
	pair <pair <int, int>, int> Q[m];
	int ans[m];
	for(int i = 0; i < m; i++){
		cin >> Q[i].first.first >> Q[i].first.second;
		Q[i].second = i;
	}
	sort(Q, Q + m);
	int cur = 1;
	for(int i = 0; i < m; i++){
		if(Q[i].first.first >= cur){
			for(; cur <= Q[i].first.first; cur++){
				modify(-a[n - cur].second, 1);
			}
		}
		ans[Q[i].second] = kthmin(Q[i].first.second, 0, n);
	}
	for(int i = 0; i < m; i++){
		cout << b[ans[i]] << '\n';
	}
}