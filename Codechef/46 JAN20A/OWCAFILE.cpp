#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353

int n, p, k;
vector <int> mult(vector<int> &A, vector<int> &B){
	vector <int> P(p, 0);
	for(int i = 0; i < p; i++){
		for(int j = 0; j < p; j++){
			P[(i*j) % p] += A[i] * B[j];
			P[(i*j) % p] %= mod;
		}
	}
	return P;
}

signed main(){
	cin >> n >> p >> k;
	vector<int> ans(p, 0), B(p, 0);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		B[x]++;
	}
	ans[1] = 1;

	while(k){
		if(k&1)
			ans = mult(ans, B);
		B = mult(B, B);
		k >>= 1;
	}
	for(int i = 0; i < p; i++)
		cout << ans[i] << ' ';
	cout << '\n';
}