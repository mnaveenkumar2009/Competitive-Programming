#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, ans = 1;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i){
			if(a[i] > a[i-1])
				ans = 2;
		}
	}
	vector< vector<int> > A;
	vector <int> s;
	for(int i = 0; i < n; i++){
		if((int)s.size()){
			if(s[s.size() - 1] >= a[i]){
				A.push_back(s);
				s.clear();
			}
		}
		s.push_back(a[i]);
	}
	if((int)s.size())
		A.push_back(s);
	int Siz = A.size();
	ans = max(ans, (int)A[Siz - 1].size());
	for(int i = 0; i < Siz - 1; i++){
		ans = max(ans, (int)A[i].size());
		if(A[i].size() == 1 || A[i+1].size() == 1)
			continue;

		if(A[i][A[i].size() - 2] < A[i+1][0] || A[i][A[i].size() - 1] < A[i+1][1]){
			ans = max(ans, (int)(A[i].size() + A[i+1].size() - 1));
		}
	}
	cout << ans << '\n';
}