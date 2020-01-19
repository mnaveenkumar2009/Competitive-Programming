#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
#define N 1001
vector<vector <int> > dp(N + 10, std::vector<int> (2*N + 10, -1));

int f(int n, int sum){
	if(dp[n][sum] != -1)
		return dp[n][sum];	
	int ret = 0;
	for(int i = )

	return dp[n][sum] = ret;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m;
	int ans = 0;
	for(int i = 1; i <= 2*N; i++){
		ans += f(n, i);
		ans %= m;
	}
	cout << ans << '\n';
}