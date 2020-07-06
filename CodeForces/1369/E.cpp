#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int n, m;
	cin >> n >> m;
	int w[n], x[m], y[m];
	vector <int> W[n];
	for(int i = 0; i < n; i++)
		cin >> w[i];
	for(int i = 0; i < m; i++){
		cin >> x[i] >> y[i];
		w[x[i]-1].push_back(i);
		w[y[i]-1].push_back(i);
	}
	stack <int> X;
	while(ans.size() < m){
		we = 0;
		for(int i = 0; i < m; i++){
			if(done[i])continue;
			if(w[x[i] - 1] >= 0 || w[y[i] - 1] >= 0){
				done[i] = 1;
				we = 1;
				ans.push_back(i);
				w[x[i] - 1]++;
				w[y[i] - 1]++;
			}
		}
		if(!we) 
			break;
	}
	if(ans.size() == n){
		cout << "ALIVE\n";
		reverse(ans.begin(), ans.end());
		for(auto i:ans)
			cout << i + 1 << ' ';
	}
	else{
		cout << "DEAD\n";
	}
}