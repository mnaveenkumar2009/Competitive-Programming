#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t;
	cin >> t;
	vector <int> v, d;
	vector <vector <int> > anss;
	int ans = 0;
	while(t--){
		string s;
		cin >> s;
		if(s == "add"){
			if(v.size() >= 40){
				cout << "OVERFLOW!!!\n";
				return 0;				
			}
			anss.push_back(v);
		}
		if(s == "for"){
			int x;
			cin >> x;
			if(x != 1)
				v.push_back(x);
			d.push_back(x);
		}
		if(s == "end"){
			if(d[d.size() - 1] != 1)
				v.pop_back();
			d.pop_back();
		}
	}
	for(auto v:anss){
		int prod = 1;
		for(auto i:v){
			prod *= i;
			if(prod >= (1LL<<32)){
				cout << "OVERFLOW!!!\n";				
				return 0;
			}
		}
		ans += prod;
		if(ans >= (1LL<<32)){
			cout << "OVERFLOW!!!\n";				
			return 0;
		}
	}

	if(ans >= (1LL<<32)){
		cout << "OVERFLOW\n";				
		return 0;
	}
	// cout << (1LL<<32) << '\n';
	cout << ans << '\n';
}