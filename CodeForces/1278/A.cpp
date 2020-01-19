#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		bool we = 0;
		string s, h;
		cin >> s >> h;
		int n = s.size(), ks = h.size();
		sort(s.begin(), s.end());
		for(int i = 0; i <= ks - n; i++){
			string x = h.substr(i, n);
			sort(x.begin(),x.end());
			if(x == s){
				we = 1;
				break;
			}
		}
		if(we)
			cout << "YES\n";
		else
			cout << "NO\n";
	}	
}