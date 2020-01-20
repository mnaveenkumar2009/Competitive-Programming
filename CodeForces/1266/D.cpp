#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, m;
	cin >> n >> m;
	vector <int> a(n, 0);
	while(m--){
		int u, v, d;
		cin >> u >> v >> d;
		a[u - 1] += d;
		a[v - 1] -= d;
	}
	vector< pair <int, int> > v;
	for(int i = 0; i < n; i++){
		if(a[i] < 0){
			v.push_back({i, -a[i]});
		}
	}
	int coun = 0;
	std::vector<int> prin;
	for(int i = 0; i < n; i++){
		if(a[i] > 0){
			int s = v.size();
			if(v[s-1].second <= a[i]){
				a[i] -= v[s-1].second;
				coun++;
				// cout << i + 1 << ' ' << v[s-1].first + 1 << ' ' << v[s-1].second << '\n';
				prin.push_back(i + 1);prin.push_back(v[s-1].first + 1);prin.push_back(v[s-1].second);
				v.pop_back();
				i--;
				continue;
			}
			else{
				coun++;
				prin.push_back(i + 1);prin.push_back(v[s-1].first + 1);prin.push_back(a[i]);
				v[s-1].second -= a[i];
			}
		}
	}
	cout << coun << '\n';
	for(int i = 0; i < prin.size()/3; i++){
		cout << prin[i*3] << ' ' << prin[i*3+1] << ' ' << prin[i*3+2] << '\n';
	}
}