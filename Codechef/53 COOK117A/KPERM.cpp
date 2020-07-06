#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MAXX = 250000;
int dp[505][MAXX], sum[505][MAXX];

const int LIM = 1e18 + 50LL;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
	for(int i = 0; i < 505; i++){
		sum[i][0] = dp[i][0] = 1;
	}
	for(int i = 0; i < MAXX; i++){
		dp[0][i] = sum[0][i] = 0;
	}
	bool we = 1;
	for(int i = 1; i < 505; i++){
	    int ic2 = (i * (i - 1))/ 2;
		for(int j = 1; j <= ic2; j++){
			dp[i][j] = 0;
			for (int kk = max(0LL,j - i + 1); kk <= j; kk++){
			    dp[i][j] += dp[i-1][kk];
			    if(dp[i][j] >= LIM){
			        dp[i][j] = LIM;
			        break;
			    }
			}
		}
	}
//	for(int i =0 ; i<= 10; i++){
//		cout << dp[3][i] << ' ';
//	}
//	cout << '\n';
// 	return 0;
	#define f(i, j) dp[i][j]
	int t;
	cin >> t;
	while(t--){
		int n, r, k;
		cin >> n >> r >> k;
		if(r * 2 > n *(n - 1)){
			cout << "-1\n";
			continue;
		}
		if(f(n, r) < k){
			cout << "-1\n";
			continue;
		}
		vector <int> rem;
		for(int i = 0; i < n; i++)
			rem.push_back(i);
		vector <int> ans(n);
		int cur = 0;
		while(cur != n-1){
// 			cout << cur << ' ' << r << ' ' <<  k << '\n';
			for(int i = 0; i < n; i++){
				if(f(n - cur - 1, r - i) >= k){
				    // if(i != 0)
					   // cout << cur << ' ' << i << ' ' << rem[i] << ' ' << k << ' ' << f(n - cur - 1, r - i) << '\n';
					ans[cur] = rem[i];
					rem.erase(rem.begin() + i);
					r -= i;
					break;
				}
				else{
				    // cout << k << ' ' << f(n - cur - 1, r - i) << '\n';
					k -= f(n - cur - 1, r - i);
				}
			}
			cur++;
		}
		ans[n-1] = rem[0];
		for(int i = 0; i < n; i++){
			cout << ans[i] + 1 << ' ';
		}cout << '\n';
	}
}