#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int b[4], cur = 1;
	for(int i = 0; i < 4; i++){
		cin >> b[i];
	}
	for(int star = 0; star < 4; star ++){
		vector<int> v(1, star);
		cur = star;
		int a[4];
		bool we= 1;
		for(int i = 0; i < 4; i++)
			a[i] = b[i];
		a[star]--;
		while(a[3] || a[2] || a[1] || a[0]){
			int i;
			for(i = 0; i < 4; i++){
				if(a[i] && abs(cur - i) == 1){
					v.push_back(i);
					a[i]--;
					cur = i;
					break;
				}
			}
			if(i == 4){
				we = 0;
				break;
			}
		}
		if(we){
			cout << "YES\n";
			for(auto i:v)cout << i << ' ';cout << '\n';
				return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
