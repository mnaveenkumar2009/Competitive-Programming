#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int x){
	int ret = (x * (x + 1))/2;
	for(int i = 40; i >= 0; i--){
		ret -= (x / (1LL << (i+1))) * (1LL << i);
		ret -= ((x % (1LL << (i+1))) >= (1LL << i)) * (1LL << i);
		if(x >= (1LL<<i))
			ret -= 1;
	}
	return ret;
}

signed main(){
	int t;
	cin >> t;
	while(t--){
		int l, r;
		cin >> l >> r;
		// cout << f(r) << ' ' << f(l-1) << '\n';
		cout << f(r) - f(l - 1) << '\n';
	}
}