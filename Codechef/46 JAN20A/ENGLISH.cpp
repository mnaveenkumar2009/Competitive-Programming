#include <bits/stdc++.h>
using namespace std;

#define int long long

int LCP(string s1, string s2) {
	int n = min(s1.length(), s2.length());
	for(int i = 0; i < n; i++)
		if(s1[i] != s2[i])
			return (i/2)*(i/2);
	return (n/2)*(n/2);
}
signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector <string> A;
		for(int i = 0; i < n; i++){
			string s;
			cin >> s;
			int S = s.length();
			string s2(2 * S, '0');
			for(int j = 0; j < S; j++){
				s2[2*j] = s[j];
				s2[2*j + 1] = s[S - j - 1];
			}
			A.push_back(s2);
		}
		sort(A.begin(), A.end());
		set <pair <int, int> > X, Y;
		int ans = 0;
		for(int i = 0; i < n - 1; i++){
			int L = LCP(A[i], A[i+1]);
			X.insert({L, i});
			Y.insert({i, L});
		}
		int last_index = n - 1;
		while(X.size()){
			auto it = *(--X.end());
			ans += it.first;
			if(X.size() == 1)break;
			auto eras1 = Y.lower_bound({it.second, it.first}), eras2 = eras1, eras3 = eras1;
			eras3--;
			eras2++;
			if(eras1 == Y.begin()){
				auto E1 = *eras1, E2 = *eras2;
				Y.erase(E1);
				Y.erase(E2);
				X.erase({E1.second, E1.first});
				X.erase({E2.second, E2.first});
				continue;
			}
			if(eras2 == Y.end()){
				auto E1 = *eras1, E3 = *eras3;
				Y.erase(E1);
				Y.erase(E3);
				X.erase({E1.second, E1.first});
				X.erase({E3.second, E3.first});
				last_index = E3.first;
				continue;
			}
			auto E1 = *eras1, E2 = *eras2, E3 = *eras3;
			Y.erase(E1);
			Y.erase(E2);
			Y.erase(E3);
			X.erase({E1.second, E1.first});
			X.erase({E2.second, E2.first});
			X.erase({E3.second, E3.first});
			int y = last_index;
			if(Y.upper_bound(E3) != Y.end()){
				y = (*Y.upper_bound(E3)).first;
			}
			int L = LCP(A[E3.first], A[y]);
			X.insert({L, E3.first});
			Y.insert({E3.first, L});
		}
		cout << ans << '\n';
	}
}