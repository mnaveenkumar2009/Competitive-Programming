#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string ans = s;
	for(int i = 0; i < n - k; i++){
		ans[i+k] = ans[i];
	}
	if(ans >= s){
		cout << n << '\n' << ans << '\n';
	}
	else{
		ans = s;
		int i;
		for(i = k - 1; i >= 0; i--){
			if(s[i] != '9'){
				break;
			}
		}
		if(i >= 0){
			ans[i]++;
			for(int j = i + 1; j < k; j++){
				ans[j] = '0';
			}
			for(int i = 0; i < n - k; i++){
				ans[i+k] = ans[i];
			}
			cout << n << '\n' << ans << '\n';
		}
		else{
			// waste of time coding
			n++;
			string ans;
			for(int i = 0; i < n; i++)
				ans.push_back('0');
			ans[0]++;
			for(int i = 0; i < n - k; i++)
				ans[i+k] = ans[i];
			cout << n << '\n' << ans << '\n';
		}
	}
}