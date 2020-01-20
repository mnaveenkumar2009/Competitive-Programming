#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		bool w = 0;
		for(int i = 0; i < s.length() - 2; i++){
			if(s[i] == s[i+1] && s[i] == s[i+1])
				w = 1;
		}
		if(w)
			cout << "YES\n";
		else
			cout << "NO\n";
	}	
}