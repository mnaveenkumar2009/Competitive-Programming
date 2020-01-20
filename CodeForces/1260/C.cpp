#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin >> t;
	while(t--){
		int a, b, k;
		cin >> a >> b >> k;
		if(a>b)
			swap(a, b);
		if(a==b){
			cout << "OBEY\n";
			continue;
		}
		int gc = __gcd(a, b);
		int x = (b - 1) / a;
		if(gc){
			if((b - gc)%a){
				x++;
			}
		}
		if(x >= k){
			cout << "REBEL\n";
		}
		else{
			cout << "OBEY\n";
		}
	}
}