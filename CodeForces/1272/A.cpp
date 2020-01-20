#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int q;
	cin >> q;
	while(q--){
		int a[3];
		cin >> a[0] >> a[1] >> a[2];
		int ans = 1e15;
		for(int i = 0; i < 3; i++)a[i]--;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				for(int k = 0; k < 3; k++)
					ans = min(ans, abs(a[0] + i - a[1] - j) + abs(a[0] + i - a[2] - k) + abs(a[2] + k - a[1] - j));
			}
		}
		cout << ans << '\n';
	}	
}