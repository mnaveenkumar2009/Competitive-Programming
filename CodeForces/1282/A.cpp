#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int a, b, c, r;
		cin >> a >> b >> c >> r;
		int L = c - r, R = c + r;
		if(a > b)
			swap(a, b);
		if(L > b || R < a){
			cout << b - a << '\n';
		}
		else{
			if(b >= R && a <= L){
				cout << b - a - abs(R-L) << '\n';
			}
			else{
				if(R >= b && L <=a){
					cout << 0 << '\n';
				}
				else{
					cout << b - a + 1 - (min(abs(R - a) + 1, abs(L - b) + 1)) << '\n';
				}
			}
		}
	}	
}