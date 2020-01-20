#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int a[n][m];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int k = 0;
				for(k = 1; i - k>=0 && i + k<n && j + k < n && j - k >= 0; k++){
					if(a[i-k][j] != a[i+k][j] || a[i][j-k]!= a[i][j+k])
						break;
				}
				ans += k;
			}
		}
		cout << ans << '\n';
	}
}