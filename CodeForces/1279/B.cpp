#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, s;
		cin >> n >> s;
		int a[n], b[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			b[i] = a[i];
			if(i)
				a[i] += a[i-1];
		}
		// int ans = lower_bound(a, a + n, s) - a;
		// if(ans == n)
		// 	ans--;
		// if(a[ans] > s)
		// 	ans--;
		// int ans2 = lower_bound(a + 1, a + n, s + a[0]) - a;
		// if(ans2 == n)
		// 	ans2--;
		// if(a[ans2] > s + a[0])
		// 	ans2--;
		// cout << max(ans + 1, ans2) << '\n';
		if(a[n-1] <= s){
			cout << "0\n";
		}
		else{
			int ans = lower_bound(a, a + n, s) - a;
			if(ans == n)
				ans--;
			if(a[ans] > s)
				ans--;
			// ans + 1 elements currently;
			if(b[ans + 1] < *max_element(b, b + ans + 1)){
				cout << (max_element(b, b + ans + 1) - b) + 1 << '\n';
			}
			else{
				cout << ans + 2 << '\n';
			}
		}
	}	
}