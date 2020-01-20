#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, m;
	cin >> n >> m;
	if(n == m && n == 1){
		cout << "0\n";
		return 0;
	}
	if(m == 1){
		for(int i = 0; i < n; i++)
			cout << i + 2 << '\n';	
		return 0;
	}
	int a[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			a[i][j] = ((n + j + 1) * (i+1))/__gcd(i + 1, n + j + 1);
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}