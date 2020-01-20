#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	bool K[26];
	memset(K, 0, sizeof(K));
	for(int i = 0; i < k; i++){
		char x;
		cin >> x;
		K[x - 'a'] = 1;
	}
	std::vector<int> a;
	for(int i = 0; i < n; i++){
		if(K[s[i] - 'a'] == 0){
			a.push_back(i);
		}
	}
	a.push_back(n);
	int ans = 0;
	for(int i = 0; i < n; i++){
		int C = *lower_bound(a.begin(), a.end(), i);
		ans += C - i;
	}
	cout << ans << '\n';
}