#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int a, k;
		cin >> a >> k;
		while(--k){
			int A = a;
			int mini = 9, maxi = 0;
			while(A){
				mini = min(mini, A % 10);
				maxi = max(maxi, A % 10);
				A /= 10;
			}
			if(mini == 0){
				break;
			}
			a += mini * maxi;
		}
		cout << a << '\n';
	}
}