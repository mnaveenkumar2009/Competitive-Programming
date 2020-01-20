#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int maxi = -10, mini = 1e9;
		for(int i = 0; i < n; i++){
			int l, r;
			cin >> l >> r;
			maxi = max(l, maxi);
			mini = min(r, mini);
		}
		cout << max(0LL, maxi - mini) << '\n';
	}
}