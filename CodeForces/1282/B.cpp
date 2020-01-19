#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int q;
	cin >> q;
	while(q--){
		int n, p, k;
		cin >> n >> p >> k;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a + n);
		vector <int> pre[k];
		for(int i = 0; i < n; i++){
			int X = a[i];
			if(pre[i%k].size() >= 1){
				X += pre[i%k][pre[i%k].size() - 1];
			}
			if(i >= k - 1)
				pre[i%k].push_back(X);
		}
		int cur = 0, ans = 0;
		for(int i = 0; i < k; i++){
			// cout << cur << '\n';
			if(cur > p)
				break;
			int buy = lower_bound(pre[(i + k - 1)%k].begin(), pre[(i + k - 1)%k].end(), p - cur) - pre[(i + k - 1)%k].begin();
			if(buy == pre[(i + k - 1)%k].size())
				buy--;
			if(buy == -1){
				ans = max(ans, i);
				cur += a[i];
				continue;
			}
			if(pre[(i + k - 1)%k][buy] > p - cur)
				buy--;
			if(buy == -1){
				ans = max(ans, i);
				cur += a[i];
				continue;
			}
			// cout << i << ' ' << buy << '\n';
			ans = max(ans, i + k * (buy + 1));
			cur += a[i];
		}
		cout << ans << '\n';
	}	
}