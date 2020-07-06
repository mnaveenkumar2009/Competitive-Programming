#include<bits/stdc++.h>
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int a[n];
		vector <int> b[2];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			b[a[i]&1].push_back(i);
		}
		int ans = 1e9 + 1;
		int cur = -1, curans = 0;
		while(1){
			if(cur + k >= n){
				ans = min(curans + 1, ans);
				break;
			}
			curans++;
			int p = (upper_bound(b[0].begin(), b[0].end(), cur + k) - b[0].begin()) - 1;
			if(p < 0)break;
			if(b[0][p] <= cur)break;
			cur = b[0][p];
		}
		cur = -1, curans = 0;
		while(1){
			if(cur + k >= n){
				ans = min(curans + 1, ans);
				break;
			}
			curans++;
			int p = (upper_bound(b[1].begin(), b[1].end(), cur + k) - b[1].begin()) - 1;
			if(p < 0)break;
			if(b[1][p] <= cur)break;
			cur = b[1][p];
		}
		if(ans == 1e9 + 1){
			cout << "-1\n";
		}
		else
			cout << ans << '\n';
	}
}