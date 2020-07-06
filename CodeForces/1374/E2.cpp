#include <bits/stdc++.h>
using namespace std;

signed main(){
	int n, m, k;
	cin >> n >> m >> k;
	bool a[n], b[n];
	int t[n], pos[4] = {0};
	vector <int> C[4];
	for(int i = 0; i < n; i++){
		cin >> t[i] >> a[i] >> b[i];
		C[a[i] + 2 * b[i]].push_back(t[i]);
	}
	for(int i = 0; i < 4; i++){
		sort(C[i].begin(), C[i].end());
	}
	
	for(int i = 0; i < k; i++){
		if(pos[3] == C[3].size())
			break;
		if(pos[2] == C[2].size())
			break;
		if(pos[1] == C[1].size())
			break;
		if(C[3][pos[3]] < ){

		}
		else{

		}
	}
}