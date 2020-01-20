#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int q;
	cin >> q;
	while(q--){
		int T = 1 + 2 + 3 + 4 + 5 + 6;
		int X;
		cin >> X;
		if(X <= 10){
			cout << "NO\n";
			continue;
		}
		if(X % (T - 7) >= 1 && X % (T - 7) <= 6)
			cout << "YES\n";
		else
			cout << "NO\n";
	}	

}