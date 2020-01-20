#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int sum[n];
	memset(sum, 0, sizeof(sum));
	sum[0] = s[0] - '0';
	for(int i = 1; i < n; i++)
		sum[i] = sum[i-1] + s[i] - '0';

	for(int i = 0; i < n - k + 1; i++){
		int tot = 0, Left = 0, Right = 0;
		if(i){
			Left = tot = sum[i-1];
		}
		tot += (Right = (sum[n-1] - sum[i + k - 1]));
		if(tot == 0 || tot == n - k){
			cout << "tokitsukaze\n";
			return 0;
		}
	}
	for(int i = 0; i < n - k + 1; i++){
		int tot = 0, Left = 0, Right = 0;
		if(i){
			Left = tot = sum[i-1];
		}
		tot += (Right = (sum[n-1] - sum[i + k - 1]));
		if(!(i == 0 || i == n-k)){
			if(!((Left == 0 || Left == i) && (Right == 0 || Right == (n - i - k)))){
				cout << "once again\n";
				return 0;
			}
		}
	}
	if(k * 2 < n){
		cout << "once again\n";
		return 0;
	}
	cout << "quailty\n";
}