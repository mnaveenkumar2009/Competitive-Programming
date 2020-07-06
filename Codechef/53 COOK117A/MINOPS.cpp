#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		string s, r;
		cin >> s >> r;
		vector <int> a;
		int n = s.size(), c = 0, d = 0;
		if(n == 1){
			cout << (s[0] != r[0]) << '\n';
			continue;
		}
		int ans = 1e14, k = 0, cur = 0;
		for(int i = 0; i < n; i++){
			if(s[i] != r[i]){
				if(d != 0)
					a.push_back(d);
				d = 0;
				cur++;
			}
			else{
				d++;
			}
		}
		if(d != 0)
			a.push_back(d);
		if(s[0] == r[0]){
		    if((int)a.size() != 0)
			    a.erase(a.begin());
		}
		if(s[n-1] == r[n-1]){
		    if((int)a.size() != 0)
			    a.pop_back();
		}
		k = a.size() + 1;
		sort(a.begin(), a.end());
		ans = cur * k;
//		cout << ans << '\n';
        int NN = a.size();
		for(int i = 0; i < NN; i++){
//			cout << a[i] << ' ';
			cur += a[i];
			ans = min(ans, (k - i - 1) * cur);
		}
		cout << ans << '\n';
	}
}