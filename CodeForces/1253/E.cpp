#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, m;
	cin >> n >> m;
	int dp[n][m], mini[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			mini[i][j] = dp[i][j] = 1e12;
	pair <int, int> x[n];
	for(int i = 0; i < n; i++)
		cin >> x[i].first >> x[i].second;
	sort(x, x + n);
	set <pair <int, int> > S;
	for(int i = 0; i < n; i++){
		int u, v;
		u = x[i].first, v = x[i].second;
		if(S.size()){
			pair <int, int> X = *S.rbegin();
			if(X.first + X.second >= u + v && (X.first - X.second <= u - v)){
				continue;
			}
		}
		// cout <<u - v << '\n';
		auto it = S.lower_bound({u - v, 0});
		xxx:
		if(it != S.end()){
			if((it->first - it->second) > (u - v)){
				// cout << u << ' ' << v << '\n';
				// cout << "sdgsdg\n";
				S.erase(it, S.end());
			}
			else{
				it++;
				goto xxx;
			}
		}
		S.insert({u, v});
	}
	n = S.size();
	// cout << n << '\n';
	int ii = 0;
	for(auto i:S)
		x[ii++] = i;
	if(n == 1){
		cout << max(0LL , max((x[0].first - 1 - x[0].second), ((m - x[0].first) - x[0].second))) << '\n';
		return 0;
	}
	// for(auto i:S){
	// 	cout << i.first << ' ' << i.second << '\n';
	// }

	int s[n];
	for(int i = 0; i < n; i++){
		s[i] = x[i].second;
		if(i){
			for(int j = 0; j < m; j++){
				int pos = lower_bound(x, x + n, make_pair(x[i].first - j, 0LL)) - x;
				if(pos == i)
					pos--;
				// cout << pos << '\n';
				int temmm = 0;
				if(pos >= 0){
					int req = (x[i].first - (j + 1)) - (x[pos].first);
					if(req < 0)
						req = 0;
					temmm = mini[pos][req];
				}
				dp[i][j] = min(dp[i][j], max(j - s[i], 0LL) + temmm);
			}
		}
		else{
			for(int j = x[i].first - 1; j < m; j++)
				dp[i][j] = max(j - s[i], 0LL);
		}
		for(int j = m - 1; j >= 0; j--){
			mini[i][j] = dp[i][j];
			if(j != m-1)
				mini[i][j] = min(mini[i][j], mini[i][j+1]);
		}
		// for(int j = 0; j < m; j++)
		// 	cout << dp[i][j] << '\n';
	}

	int ansss = 1e9;
	for(int i = 0; i < n; i++){
		ansss = min(ansss, mini[i][m - x[i].first]);
	}
	cout << ansss << '\n';
}