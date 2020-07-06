#include <bits/stdc++.h>
using namespace std;
#define int long long

int ran(int x){
	return (rand() % x) + 1;
}

signed main(){
	srand(time(0));
	int t = 1e5;
	cout << t << '\n';
	while(t--){
		int n, m;
		n = ran(4) + 1, m = ran(4) + 1;
		int x1 = ran(n);
		int y1 = ran(m - 1);
		int x2 = ran(n);
		int y2 = y1 + ran(m - y1); // (y1 + 1) -> m =  y1 + (1 -> m - y1)

		// y1 < y2;
		cout << n << ' ' << m << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
	}
}