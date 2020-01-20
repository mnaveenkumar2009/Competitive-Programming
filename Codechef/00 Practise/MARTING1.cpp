#include <bits/stdc++.h>
using namespace std;
#define ld long double

ld dp[2000006][30], n;
ld F(int N, int X){
	if(N <= 0 || N >= 2*n)
		return 0;
	if(dp[N][X] != 0)
		return dp[N][X];
	return dp[N][X] = (((1 + F(N + (1<<X), 0)) + (1 + F(N - (1<<X), X + 1))) / 2.0);
}

signed main(){
    cin >> n;
    cout << fixed << setprecision(10) << F(n, 0) << '\n';
}