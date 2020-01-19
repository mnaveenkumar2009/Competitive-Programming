#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		n *= 2;
		int a[n], sum[n], tot = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			sum[i] = (a[i] == 1)? 1 : -1;
			tot += sum[i];
		}
		if(tot == 0){
			cout << "0\n";
			continue;
		}
		map <int, int> m;
		m[0] = n;
		m[sum[n-1]] = n - 1;
		// cout << "sum\n" << sum[n-1] << ' ';
		for(int i = n-2; i >= n/2; i--){
			sum[i] += sum[i+1];
			// cout <<sum[i] << ' ';
			m[sum[i]] = i;
		}
		// cout << '\n';
		int ans = m[0], cur = 0;
		for(int i = 0; i < n/2; i++){
			cur += (a[i] == 1)? 1 : -1;
			if(cur == 0)
				ans = min(ans , n - i - 1);
			if(m[-cur])
				ans = min(ans, m[-cur] - (i + 1));
		}
		cout << ans << '\n';
	}
}