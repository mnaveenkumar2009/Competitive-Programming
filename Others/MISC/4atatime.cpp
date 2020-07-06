#include<bits/stdc++.h>
using namespace std;
#define int long long

int DP(vector <int> a){
    int n = a.size(), dp[4][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = a[0];
    
    for(int i = 1; i < n; i++)
        dp[0][i] = a[i] + dp[0][i-1];
        
    for(int k = 1; k < 4; k++)
        for(int i = k; i < n; i++)
            dp[k][i] = a[i] * dp[k-1][i-1] + dp[k][i-1];
            
    return dp[3][n-1];
}

int brute(vector <int> a){
    int ret = 0;
    for(auto i1 = a.begin(); i1 != a.end(); i1++)
        for(auto i2 = i1 + 1; i2 != a.end(); i2++)
            for(auto i3 = i2 + 1; i3 != a.end(); i3++)
                for(auto i4 = i3 + 1; i4 != a.end(); i4++)
                    ret += *i1 * *i2 * *i3 * *i4;
    return ret;
}

int comb(vector <int> a){
	int total = 0, square_sum = 0;
	for(int i:a){
		total += i;
		square_sum += i * i;
	}
	int ans = total * total * total * total;
	for(int i:a){
		ans -= i * i * i * i; // a^4
		ans -= 4 * i * i * i * (total - i); // a^3b
		ans -= 3 * i * i * (square_sum - (i * i)); // a^2b^2
		ans -= 6 * i * i * ((total - i) * (total - i) - (square_sum - i * i)); //a^2bc
	}
	return ans/24;
}

signed main(){
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << DP(a) << '\n';
	cout << brute(a) << '\n';
	cout << comb(a) << '\n';
}