#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int q;
	cin >> q;
	while(q--){
		int L = 0, R = 0, D = 0, U = 0;
		string s;
		cin >> s;
		for(auto i:s){
			if(i == 'L')
				L++;
			if(i == 'R')
				R++;
			if(i == 'U')
				U++;
			if(i == 'D')
				D++;
		}
		L = R = min(L, R);
		U = D = min(U, D);
		if(U == 0){
			L = R = min(L, 1LL);
		}
		if(L == 0){
			U = D = min(U, 1LL);
		}
		cout << L + R + U + D << '\n';
		while(L--)
			cout << 'L';
		while(U--)
			cout << 'U';
		while(R--)
			cout << 'R';
		while(D--)
			cout << 'D';
		cout << '\n';
	}	
}