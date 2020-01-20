#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int x[n], h[n];
		for(int i = 0; i < n; i++){
			cin >> x[i] >> h[i];
		}
		sort(h, h + n);
		sort(x, x + n);
		vector <int> siz;
		for(int i = 0; i < n; i++){
			if(i!=n-1 && i!=0)
				siz.push_back(x[i + 1] - x[i - 1]);
			else{
				if(i==n-1){
					siz.push_back(x[i] - x[i - 1]);
				}
				else{
					siz.push_back(x[i + 1] - x[i]);
				}
			}
		}
		sort(siz.begin(), siz.end());
		// cout << siz.size() << '\n';
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans += siz[i] * h[i];
		cout << ans << '\n';
	}
}