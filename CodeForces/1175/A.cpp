#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int N, K;
		cin >> N >> K;
		int ans = 0;
		while(N){
			ans += N%K;
			ans += 1;
			N/=K;
		}
		cout << ans - 1 << '\n';
	}
}