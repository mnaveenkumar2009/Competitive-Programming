#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int l;
		string s;
		cin >> l >> s;
		if(l > 1){
			sort(s.begin(), s.end());
			cout << s << '\n';
		}
		else{
			string ans = s;
			int n = s.size();
			while(n--){
				s = s[s.size() - 1] + s.substr(0, s.size() - 1);
				ans = min(ans, s);
			}
			cout << ans << '\n';
		}
	}
}