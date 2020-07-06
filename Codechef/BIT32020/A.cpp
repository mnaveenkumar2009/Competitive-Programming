#include<bits/stdc++.h>
using namespace std;

#define int long long
#define f abs
signed main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int ans = 0;
		for(auto i:s){
			ans += min(f(i-'a'),min(f(i-'e'), min(f(i-'i'), min(f(i-'o'), f(i-'u')))));
		}
		cout << ans << '\n';
	}
}