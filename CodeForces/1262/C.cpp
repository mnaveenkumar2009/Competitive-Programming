#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int cur = 0;
		string s;
		cin >> s;
		vector<pair <int, int> > prin;
		for(int i = 0; i < k - 1; i++){
			if(s[2*i] == ')'){
				for(int j = 2*i + 1; j < n; j++){
					if(s[j] == '('){
						prin.push_back({2*i, j});
						reverse(s.begin() + 2*i, s.begin() + j + 1);
						break;
					}
				}
			}
			if(s[2*i + 1] == '('){
				for(int j = 2*i + 2; j < n; j++){
					if(s[j] == ')'){
						prin.push_back({2*i + 1, j});
						reverse(s.begin() + 2*i + 1, s.begin() + j + 1);
						break;
					}
				}
			}
		}
		for(int i = 2*k - 2; i < n; i++){
			if(s[i] == ')'){
				for(int j = i + 1; j < n; j++){
					if(s[j] == '('){
						prin.push_back({i, j});
						reverse(s.begin() + i, s.begin() + j + 1);
						break;
					}					
				}
			}
		}
		// cout << s << '\n';
		cout << prin.size() << '\n';
		for(auto i:prin)
			cout << i.first + 1 << ' ' << i.second + 1 << '\n';
 
	}
}