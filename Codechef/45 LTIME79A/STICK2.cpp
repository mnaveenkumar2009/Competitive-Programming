#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

int dp[60][20000];
int f(int n, int sum){
	if(dp[n][sum] != -1)
		return dp[n][sum];
	if(sum == 0)
		return 1;
	if(n == 1){
		return (sum <= 1);
	}
	int ret = f(n - 1, sum);
	if(sum - n >= 0){
		ret += f(n - 1, sum - n);
	}
	return (dp[n][sum] = ret % mod);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 60; i++)
    for(int j = 0; j < 20000; j++)
    	dp[i][j] = -1;
    for(int i = 1; i < 60; i++)
    for(int j = 1; j < 20000; j++)
    	f(i, j);
    // int nnn;
    // cin >> nnn;
    // for(int i = 0; i <= 100; i++)
    // 	cout << f(nnn, i) << ' ';cout << '\n';
    int prevans = 0;
    for(int nnn = 4; nnn <= 20; nnn++){
	    int ans = 0;
	    for(int j = nnn + 1; j <= 20000; j++){
			ans = (ans + f(nnn - 1, j));
		}
		cout << ans << ' ' << ans - 2*prevans << '\n';
		prevans = ans;
	}
    // for(int i = 1; i <= 100; i++){
    // 	cout << f(3, i) << ' ';
    // }
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = 0;
		// for(int i = 1; i <= ((n * (n + 1) )>> 1); i++){
		// 	// ans = (ans + f(n, i)) % mod;
		// 	// cout << f(n, i) << ' ';
		// }
		// vector <int> b(2000, 0);
		// int ans2 = 0;
		// for(int mask = 0; mask < (1 << (n - 1)); mask++){
		// 	int maxi = 0, s = 0;
		// 	for(int j = 0; j < n; j++){
		// 		if(mask & (1<<j)){
		// 			s += j + 1;
		// 			maxi = max(maxi, j + 1);
		// 		}
		// 	}
		// 	if(s - maxi > maxi){
		// 		// ans2++;
		// 		// cout << mask << '\n';
		// 	}
		// 	// if(s == )
		// 	b[s]++;
		// }
		// cout << "dgg\n";
		// cout << f(4, 9) << '\n';
		// cout << f(4, 3) << '\n';
		// cout << f(5, 9) << '\n';
		for(int i = 3; i <= n; i++){
			for(int j = i + 1; j <= 20000; j++){
				ans = (ans + f(i - 1, j)) % mod;
				if( i== n && j < 30){
					// cout << f(i - 1, j) << ' ';
					// cout << b[j] << ' ';
					// if(b[j] != f(i-1, j)){
						// cout << "j " << j << ' '  << f(i - 1, j) << ' ' << '\n';
					// }
				}
			}
		}
		// cout << ans2 << '\n';
		cout << ans << '\n';
	}	
}