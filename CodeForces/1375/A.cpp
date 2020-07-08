#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(i&1){
				a[i] = -abs(a[i]);
			}
			else
				a[i] = abs(a[i]);
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}