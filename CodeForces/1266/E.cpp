#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin >> n;
	int sum = 0, a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	map<pair<int,int>, int> m;
	int q;
	cin >> q;
	while(q--){
		int u, v, w;
		cin >> u >> v >> w;
		int cur = m[{u, v}];
		if(cur){
			a[cur - 1]++;
			if(a[cur - 1] > 0)
				sum++;
		}
		m[{u, v}] = w;
		if(w){
			a[w - 1]--;
			if(a[w-1] >= 0)
				sum--;
		}
		cout << sum << '\n';
	}
}