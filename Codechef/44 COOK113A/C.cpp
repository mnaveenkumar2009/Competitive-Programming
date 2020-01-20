#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int l, int r, int k, int n){
	cout << "l r " << l << ' ' << r << ' ' << n << '\n';
	if((r - l + 1) * n < k)
		return 0;
	for(int i = log2(r); i >= 0; i--){
		if(r & (1LL << i)){
			if(l & (1LL << i)){
				int newl = l ^ (1LL << i);
				int newr = (r - ((r >> i) << i));
				// cout << newl << ' ' << newr << '\n';
				if((newr - newl + 1) * n * (r>>i) >= k)
					return (1LL << i) + f(newl, newr, k, (r >> i) * n);
			}
			else{
				if(((r & ((1LL << i)-1)) + 1) * (r>>x) * n >= k)
					return f((1LL << i), r, k, n);
			}
		}
		else{
			if(min(1LL << i, 1LL<<(i+1) - l) * n * (r >> (i + 1)) >= k){
				return f(max(1LL << i, l), (1LL << (i + 1)) - 1, k, n * ((r >> (i+1))));
			}
		}
	}
	return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int l, r, k;
		cin >> l >> r >> k;
		cout << f(l, r, k, 1) << '\n';
	}
}