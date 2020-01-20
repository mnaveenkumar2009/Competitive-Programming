#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
	int n, m;
	cin >> n >> m;
	int dp[n][m], mini[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			mini[i][j] = dp[i][j] = 1e9;
	pair <int, int> x[n];
	set <pair <int, int> > S;
	for(int i = 0; i < n; i++){
		// cin >> x[i].first >> x[i].second;
		int u, v;
		cin >> u >> v;
		if(S.size()){
			pair <int, int> X = *S.rbegin();
			// cout << X.first << ' ' << X.second << '\n';
			// for(auto i:S){
			// 	cout << i.first << ' ' << i.second << '\n';
			// }
			// cout << '\n';
			if(X.first + X.second >= u + v){
				// cout << u << ' ' << v << '\n';
				continue;
			}
		}
		auto it = S.lower_bound({u - v, 0});
		if(it != S.end()){
			if((it->first - it->second) > (u - v)){
				S.erase(it, S.end());
			}
		}
		S.insert({u, v});
	}
	sort(x, x + n);
	n = S.size();
	cout << n << '\n';
	int ii = 0;
	for(auto i:S)
		x[ii++] = i;
	if(n == 1){
		cout << max(0LL , max((x[0].first - 1 - x[0].second), ((m - x[0].first) - x[0].second))) << '\n';
		return 0;
	}
	for(auto i:S){
		cout << i.first << ' ' << i.second << '\n';
	}
 
	int s[n];
	for(int i = 0; i < n - 1; i++){
		s[i] = x[i].second;
		if(i){
			for(int j = 0; j < m; j++){
				int req = (x[i].first - (j + 1)) - (x[i-1].first);
				if(req < 0)
					req = 0;
				dp[i][j] = min(dp[i][j], max(j - s[i], 0LL) + mini[i-1][req]);
			}
		}
		else{
			for(int j = x[i].first - 1; j < m; j++){
				dp[i][j] = max(j - s[i], 0LL);
			}
		}
		for(int j = m - 1; j >= 0; j--){
			mini[i][j] = dp[i][j];
			if(j!=m-1)
				mini[i][j] = min(mini[i][j], mini[i][j+1]);
		}
	}
	// n - 1;
	int i = n - 1;
	for(int j = m - x[n-1].first; j < m; j++){
		s[n-1] = x[n-1].second;
		int req = (x[i].first - (j + 1)) - (x[i-1].first);
		if(req < 0)
			req = 0;
		dp[i][j] = min(dp[i][j], max(j - s[i], 0LL) + mini[i-1][req]);
	}
	for(int j = m - 1; j >= 0; j--){
		mini[i][j] = dp[i][j];
		if(j!=m-1)
			mini[i][j] = min(mini[i][j], mini[i][j+1]);
	}
 
	cout << mini[n-1][m - x[n-1].first] << '\n';
}