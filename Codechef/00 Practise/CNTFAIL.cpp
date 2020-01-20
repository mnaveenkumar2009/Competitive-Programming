#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		if(n==1){
			cout << "-1\n";
			continue;
		}
		if(a[0] == n-1 && a[1] == n-1){
			cout << "0\n";
			continue;
		}
		int ans = 0;
		int b = *max_element(a, a + n);
		for(int i = 0; i < n; i++){
			if(a[i] == b)
				ans++;
		}
		for(int i = 0; i < n; i++){
			if(a[i] == b){
				if(a[i] != n-ans){
					ans = -1;
					break;
				}
			}
			else{				
				if(a[i] != n-ans -1){
					ans = -1;
					break;
				}
			}
		}
		cout << ans << '\n';

	}
}