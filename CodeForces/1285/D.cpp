#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100006];
int f(int l, int r, int cur, int bi){
	// cout << l << ' ' << r << ' ' << cur << ' ' << bi << '\n';
	for(int m = bi; m >= 0; m--){
		int Or = 0, And = 1;
		int pos = 1e9;
		for(int i = l; i <= r; i++){
			Or |= (a[i] >> m) & 1;
			And &= (a[i] >> m) & 1;
			if((a[i] >> m) & 1)
				pos = min(pos, i);
		}
		// cout << Or << ' ' << And << ' ' << m << '\n';
		if(Or != And){
			cur |= (1LL << m);
			return min(f(l, pos - 1, cur, m - 1), f(pos, r, cur, m - 1));
		}
	}
	return cur;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    sort(a, a + n);
    cout << f(0, n - 1, 0, 32) << '\n';
}