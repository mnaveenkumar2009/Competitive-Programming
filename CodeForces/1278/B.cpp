#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
	int q;
	cin >> q;
	vector <int> a(1, 1);
	for(int i = 1; i < 1e6; i++){
		a.push_back(a[i - 1] + i + 1);
	}
	while(q--){
		int aa, b;
		cin >> aa >> b;
		int x = abs(aa - b);
		if(x == 0){
			cout << "0\n";
			continue;
		}
		// int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
		// if((a[pos]&1) != (x&1)){
		// 	pos++;
		// }
		// cout << pos + 1 << '\n';
		for(int i = 1; i < 1e6; i++){
			int S = (i * (i + 1))/2;
			if(x <= S && ((x&1) == (S&1))){
				cout << i << '\n';
				break;
			}
		}
	}	
}