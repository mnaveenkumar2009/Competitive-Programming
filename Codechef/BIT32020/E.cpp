#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, K;
int a[1005], sum[1005], dp[1003][1003];
bool done[1003][1002];

int g(int i, int j){
	if(j >= i)
		return (sum[j] - sum[i-1]);
	return 0;
}

int h(int i, int j){
	return g((i+j)/2 + 1, j) - g(i, (i+j-1)/2);
}

int f(int i, int k){
	if(done[i][k]){
		return dp[i][k];
	}
	done[i][k] = 1;
	if(k == 1)
		return dp[i][k] = h(i, n);
	int ans = 1e18;
	for(int j = i + 1; j <= n; j++){
		ans = min(ans, h(i, j - 1) + f(j, k - 1));
	}
	return dp[i][k] = ans;
}
signed main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> K;
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= K; j++){
				done[i][j] = 0;
			}
		}
		sum[0] = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			sum[i] = a[i] + sum[i-1];
		}
		// cout << f(4, 2) << '\n';
		// for(int i = 1; i <= n; i++){
		// 	for(int j = 1; j <= K; j++){
		// 		cout << f(i, j) << ' ';
		// 	}cout << '\n';
		// }
		cout << f(1, K) << '\n';
	}
}