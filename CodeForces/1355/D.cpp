#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int n, s;
	cin >> n >> s;
	int x = s - (n - 1);
	if(x <= n){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int i = 0; i < n - 1; i++){
		cout << "1 ";
	}
	cout << x << '\n' << n << '\n';
}