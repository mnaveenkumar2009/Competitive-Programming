#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const ll N = 2e6+2;
const ll N2 = 2*N;
class STreeMin{
	public:
		STreeMin(){
			tree.resize(2*N, 1e15);
			for(int i = 0; i < 2*N; i++)
				tree[i] = 1e15;
		}
		vector <ll> tree;
		void modify(ll p, ll value) {
		    for (tree[p += N] = value; p > 1; p >>= 1) 
		    	tree[p>>1] = min(tree[p],tree[p^1]);
		}
		ll query(ll l, ll r) {
		    ll res = 1e15;
		    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		        if (l&1) res = min(res, tree[l++]);
		        if (r&1) res = min(tree[--r], res);
		    }
		    return res;
		}
}Rb, Ra;
class STreeMax{

	public:
		STreeMax(){
			tree.resize(2*N);
		}
		ll n = N;
		vector <ll> tree;
		void modify(ll p, ll value) {
		    for (tree[p += n] = value; p > 1; p >>= 1) 
		    	tree[p>>1] = max(tree[p],tree[p^1]);
		}
		ll query(ll l, ll r) {
		    ll res = 0;
		    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		        if (l&1) res = max(res, tree[l++]);
		        if (r&1) res = max(tree[--r], res);
		    }
		    return res;
		}
}Lb, La;

int solve(){
	int n;
	cin >> n;
	int a[n], b[n], c[n], d[n];
	map <int, int> X;
	set <int> S;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i] >> d[i];
		S.insert(a[i]);
		S.insert(b[i]);
		S.insert(c[i]);
		S.insert(d[i]);
	}
	int coun = 0;
	for(auto i:S){
		X[i] = coun++;
	}
	for(int i = 0; i < n; i++){
		a[i] = X[a[i]];
		b[i] = X[b[i]];
		c[i] = X[c[i]];
		d[i] = X[d[i]];
// 		cout << a[i] << ' ' << b[i] << ' ' << c[i] << ' ' << d[i] << '\n';
	}
	set <int> La1[N], Lb1[N], Ra1[N], Rb1[N];
	for(int i = 0; i < n; i++){
		La1[c[i]].insert(a[i]);
		Lb1[a[i]].insert(c[i]);
		Ra1[c[i]].insert(b[i]);
		Rb1[a[i]].insert(d[i]);
		if(Lb.query(a[i], a[i]+1) < c[i])
			Lb.modify(a[i], c[i]);
		if(La.query(c[i], c[i]+1) < a[i])
			La.modify(c[i], a[i]);
		if(Rb.query(a[i], a[i]+1) > d[i])
			Rb.modify(a[i], d[i]);
		if(Ra.query(c[i], c[i]+1) > b[i])
			Ra.modify(c[i], b[i]);
	}
	for(int i = 0; i < n; i++){
		if(Rb.query(a[i], b[i]+1) < c[i]){
			return 0;
		}
		if(Lb.query(a[i], b[i]+1) > d[i]){
			return 0;
		}
		if(Ra.query(c[i], d[i]+1) < a[i]){
			return 0;
		}
		if(La.query(c[i], d[i]+1) > b[i]){
			return 0;
		}
	}
	return 1;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	if(solve()){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}