#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n], dp[n];
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		for(int i = 0; i < n; i++){
			if(i - a[i] == -1){
				dp[i] = 1;
			}
			if(i - a[i] < -1){
				dp[i] = 0;
			}
			if(i - a[i] >= 0){
				dp[i] = 1 + dp[i - a[i]];
			}
		}
		cout << *max_element(dp, dp + n) << '\n';;
	}
}