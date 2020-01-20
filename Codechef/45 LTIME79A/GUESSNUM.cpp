#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int a, m;
		cin >> a >> m;
		vector <int> ans;
		for(int i = 1; i*i <= m; i++){
			if(m % i == 0){
				int L = m/i - 1;
				if(L%a == 0){
					ans.push_back((L/a) * i);
				}
				if(i * i  != m){
					int L = i - 1;
					if(L%a == 0){
						ans.push_back((L/a) * (m/i));
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		if(ans.size())
			if(ans[0] == 0){
				ans.erase(ans.begin());
			}
		cout << ans.size() << '\n';
		for(auto i:ans)cout << i << ' ';cout << '\n';
	}	
}