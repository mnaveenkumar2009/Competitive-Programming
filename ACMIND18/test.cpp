#include "bits/stdc++.h"
using namespace std;
vector <long long> dp[2505];
long long ways[2505][2505];
int c[2505][2505];
const int mod = 1000000000 + 7;

int main(int argc, char const *argv[])
{
	for(int i = 0; i <= 2500; i++) {
		for(int j = 0; j <= 2500; j++) {
			if(i == 0) {
				ways[i][j] = 1;
			} else {
				long long cnt = ((j * (j + 1) / 2) + 1) % mod;
				ways[i][j] = (ways[i - 1][j] * cnt) % mod;
			}
		}
	}
	for(int i = 0; i <= 2500; i++) {
		c[i][0] = 1;
		for(int j = 1; j <= i; j++) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
	int ans = 0;
	dp[0].resize(2501);
	for(int i = 1; i <= 2500; i++) {
		int range = 2500 / i;
		dp[i].resize(range + 1);
		for(int j = 1; j <= range; j++) {
			dp[i][j] = (ways[i][j] - ways[i][j - 1]) % mod;
			for(int x = 1; x <= i; x++) {
				for(int y = 1; y <= j; y++) {
					if(x == i && y == j) continue;
					dp[i][j] -= ((dp[x][y] * c[i][x]) % mod) * ways[i - x][j - y];
					dp[i][j] %= mod;
				}
			}
			if(dp[i][j] < 0) dp[i][j] += mod; 
		} 	
	}
	int t;
	scanf("%d", &t);
	while(t--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%lld\n", dp[x][y]);
	}
	return 0;
}