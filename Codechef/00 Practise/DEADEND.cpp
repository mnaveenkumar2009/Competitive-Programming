#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t, a[1000006];
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map <int, bool> X;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			X[a[i]] = 1;
		}
		sort(a, a + n);
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(X[a[i] - 1] || X[a[i] + 1])
				continue;
			X[a[i]+1] = 1;
			ans++;
		}
		cout << ans << '\n';
	}
}