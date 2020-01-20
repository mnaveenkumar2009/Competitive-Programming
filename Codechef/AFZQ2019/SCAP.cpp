#include <bits/stdc++.h>
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	#define int long long
	ll n, m;
	cin >> n >> m;
	vector<ll> l(n), w(n);
	for(int i = 0; i < n; ++i) cin >> l[i];
	for(int i = 0; i < n; ++i) cin >> w[i];
	sort(l.begin(), l.end());
	sort(w.begin(), w.end());
	reverse(w.begin(), w.end());
	// sort(w, w+n);
	ll lo = 0, hi = 1e18;
	while(lo < hi) {
		// cout << lo <<' ' << hi << '\n';
		ll mid = (lo + hi) / 2;
		if(mid == hi)mid --;
		// Code
		ll ef = 0, pos = 1;
		for(int i = 0; i < n; ++i) {
			if(w[i] == 0) continue;
			ef += max((ll)0, l[i] - (ll)floor((double)mid / (double)w[i]));
			if(ef > m) {
				pos = 0;
				break;
			}
		}
		// Code over
		if(pos) 
			hi = mid;
		else 
			lo = mid + 1;
	}
	cout << lo << '\n';
    return 0;
}