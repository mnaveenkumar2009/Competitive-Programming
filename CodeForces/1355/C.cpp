#include <bits/stdc++.h>
using namespace std;

#define int long long

int n2(int x, int star){
	int X = x;
	x = x * (x + 1);
	return x/2 + (star - 1) * X;
}
signed main(){
	int a, b, c, d, ans = 0;
	cin >> a >> b >> c >> d;
	for(int i = c; i <= d; i++){
		int l = i - b + 1, r = i - a + 1, star = 1;
		if(l < b){
			star = b - l + 1;
		}
		l = max(b, l);
		r = max(b, r);
		r = min(c, r);
		ans += (c - r) * (b-a + 1);
		if(l <= r){
			star = min(star, b - a + 1);
			ans += n2(r - l + 1, star);
		}
//		cout << l << ' ' << r <<' '  << i << '\n';
	}
	cout << ans;
}