#include <bits/stdc++.h>
using namespace std;

signed main(){
	srand(time(0));
	cout << "1\n";
	int n = 5;
	int m = 5;
	cout << n << ' ' << m << '\n';
	for(int i = 0; i < m; i++){
		int v = 1 + rand() % (n - 1);
		int u = rand() % v;
		cout << u + 1 << ' ' << v + 1 << '\n';
	}
}