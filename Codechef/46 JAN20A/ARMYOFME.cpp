#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 5001

int p[N], dp[N][N];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	memset(dp, -1, sizeof(dp));
	int n, q;
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	for(int i = 0; i < n; i++){
		int maxi = p[i], mini = p[i];
		for(int j = i; j < n; j++){
			maxi = max(maxi, p[j]);
			mini = min(mini, p[j]);
			if(maxi - mini == j - i)
				dp[i][j] = j - i + 1;
			else
				dp[i][j] = dp[i][j - 1];
		}
	}
	for(int i = n - 2; i >= 0; i--){
		for(int j = i; j < n; j++){
			dp[i][j] = max(dp[i][j], dp[i+1][j]);
		}
	}
	int ans = 0;
	while(q--){
		int l, r;
		cin >> l >> r;
		l = (l + ans - 1) % n;
		r = (r + ans - 1) % n;
		if(l > r)
			swap(l, r);
		cout << (ans = dp[l][r]) << '\n';
	}
}