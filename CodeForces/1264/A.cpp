#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		if(n < 10 || a[0] == a[n-1]){
			cout << "0 0 0\n";
			continue;
		}
		// cout << "SAfdsg\n";
		int maxlim = (n-2)/2;
		bool we = 1;
		while(maxlim > 0){
			if(a[maxlim] == a[maxlim + 1])
				maxlim--;
			else
				break;
		}
		if(maxlim < 4){
			cout << "0 0 0\n";
			continue;			
		}
		// cout << maxlim << '\n';
		int ans[3];
		ans[0] = ans[1] = ans[2] = -1;
		for(int i = 0; i < n; i++){
			if(a[i] != a[i+1]){
				ans[0] = i + 1;
				break;
			}
		}
		// cout << ans[0] << '\n';
		for(int i = ans[0]*2; i < maxlim; i++){
			if(a[i] != a[i + 1]){
				ans[1] = i + 1 - (ans[0]);
				break;
			}
		}
		ans[2] = maxlim + 1 - ans[0] - ans[1];
		if(ans[0] < ans[1] && ans[0] < ans[2] && ans[1] >= 0 && ans[2] >= 0 && ans[0] >= 0){
			cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
		}
		else{
			cout << "0 0 0\n";			
		}
	}
}