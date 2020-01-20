#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n, m;
	cin >> n >> m;
	int a[n], sum[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		sum[i] = a[i];
		if(i)
			sum[i] += sum[i-1];
	}

	vector <int> ans(n, 0);
	for(int i = 0; i < n; i++){
		ans[i] = sum[i];
		if(i - m >= 0)
			ans[i] += ans[i-m];
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}