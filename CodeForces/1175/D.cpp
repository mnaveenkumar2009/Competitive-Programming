#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector <int> X;
	int cur = 0;
	for(int i = n - 1; i >= 0; i--){
		cur += a[i];
		if(i != 0)
			X.push_back(cur);
	}
	int ans = cur;
	sort(X.begin(), X.end());
	reverse(X.begin(), X.end());
	for(int i = 0; i < k - 1; i++){
		ans += X[i];
	}
	cout << ans << '\n';
}