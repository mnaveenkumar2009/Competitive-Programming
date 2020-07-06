#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n, i;
		cin >> n;
		string s;
		cin >> s;
		for(i = n-1; i >= 0; i--){
			if(s[i] == '0'){
				bool we = 0;
				for(int j = i - 1; j >= 0; j--){
					if(s[j] == '1'){we = 1;break;}
				}
				if(!we)
					i = 0;
				break;
			}
		}
		// cout << i << '\n';
		i = max(i, 0LL);
		cout << s.substr(i, s.size() - i) << '\n';
	}
}