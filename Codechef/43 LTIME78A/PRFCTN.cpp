#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		map <int, vector<int> > X;
		set <int> indices;
		set <int> S;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			indices.insert(i);
			X[a[i]].push_back(i);
			S.insert(a[i]);
		}
		int ans = 0;
		S.erase(S.begin());
		for (auto rit=S.rbegin(); rit != S.rend(); ++rit){
			auto i = *rit;
			for(auto j:X[i]){
				auto it1 = (upper_bound(X[i].begin(), X[i].end(), j));
				auto it2 = indices.upper_bound(j);
				if(it1 == X[i].end() || it2 == indices.end()){
					ans++;
				}
				else{
					if((*it1) != (*it2))
						ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}