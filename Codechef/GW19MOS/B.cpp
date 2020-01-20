#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n][n], cost[k][1 << (n - k)], sum = 0, cost_m[1 << (n - k)];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> a[i][j];
				sum += a[i][j];
			}
		}
		sum /= 2;
		for(int mask = 0; mask < (1 << (n-k)); mask++){
			cost_m[mask] = 0;
			for(int i = k; i < n; i++){
				if(mask & (1 << (i -k))){
					for(int j = i+1; j < n; j++){
						if(mask & (1 << (j - k))){
							cost_m[mask] += a[i][j];
						}
					}
				}
			}
		}
		for(int i = 0; i < k; i++){
			for(int mask = 0; mask < (1 << (n-k)); mask++){
				cost[i][mask] = cost_m[mask];
				for(int j = k; j < n; j++){
					if(mask & (1 << (j-k)))
						cost[i][mask] += a[i][j];
				}
			}
		}
		int dp[k][1 << (n - k)];
		for(int i = 0; i < k; i++){
			for(int mask = 0; mask < (1 << (n-k)); mask++){
				if(i){
					dp[i][mask] = dp[i-1][0] + cost[i][mask];
					for(int m = mask; m > 0; m = (m-1) & mask){
				    	dp[i][mask] = max(dp[i][mask], dp[i-1][m] + cost[i][mask ^ m]);
					}
				}
				else
					dp[0][mask] = cost[0][mask];
			}
		}
		cout << sum - dp[k-1][(1 << (n - k)) - 1] << '\n';
	}
}