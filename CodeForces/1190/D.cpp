#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	map <int, vector <int> > X;
	map <int, int> P;
	set <int> unx;
	vector<int> Xs(1, 1e11);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		X[y].push_back(x);	
		unx.insert(x);
	}
	for(auto x:unx)
		Xs.push_back(x);	
	sort(Xs.begin(), Xs.end());
	for(int i = 0; i < Xs.size(); i++)
		P[Xs[i]] = i;
	int no_x = 0, ans = 0;
	for(auto points : X){
		no_x++;
		vector <int> A = points.second;
		sort(A.begin(), A.end());
		A.push_back(Xs[Xs.size() - 1]);
		int N = A.size();
		cout << points.first << ' ' << N << '\n';
		for(int i = 0; i < N - 1; i++){
			cout << P[A[i]] << ' ' << P[A[i+1]] << '\n';
			ans += (P[A[i+1]] - P[A[i]]) * (P[A[i]] + 1);
		}
	}

	cout << ans << '\n';
}