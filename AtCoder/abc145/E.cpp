#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, t;
	cin >> n >> t;
	pair <int, int> a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a+n);
	int dp[t];
	memset(dp, 0, sizeof(dp));
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = t-1; j >= 0; j--){
			if(a[i].first + j < t)
				dp[j + a[i].first] = max(dp[j + a[i].first], dp[j] + a[i].second);
			ans = max(ans, dp[j] + a[i].second);
		}
	}
	cout << ans << '\n';
}