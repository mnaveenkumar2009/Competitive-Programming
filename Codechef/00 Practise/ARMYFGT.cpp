#include <bits/stdc++.h>
using namespace std;

int main(){
	#define int long long
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool we = 1;
		int l = 1;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			int b = __gcd(x, l);
			if(((1e18 + 20)/(long double)x)*b < l){
				we = 0;
			}
			l = (l * x) / b;
		}
		// cout << l << '\n';
		int L, R;
		cin >> L >> R;
		if(we){
			int ans = (R/l) - (L - 1)/l;
			cout << R - L + 1 - ans << '\n';
		}
		else{
			cout << R - L + 1 << '\n';
		}
	}
}