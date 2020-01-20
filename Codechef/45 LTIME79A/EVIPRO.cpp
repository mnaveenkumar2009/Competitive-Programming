#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.length(), c = 0;
		for(int i = 0; i < n - 1; i++)
			if(s[i] == s[1+i])
				c++;
		int ans = (c * n * (n + 1)) / 2;
		for(int i = 0; i < n - 1; i++){
			if(s[i] == s[1+i]){
				// i + 1 as L or i as R
				ans -= n - i;
				ans -= i + 1;
				ans++;
			}
			else{
				ans += n - i;
				ans += i + 1;	
				ans--;
			}
		}
		cout << ans << '\n';
	}	
}