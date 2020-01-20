#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n, m, q, l, r;
	cin >> n;
	while(cin >> n >> m >> q){		
		vector <int> a(n + 1, 0), b(n + 1, 0), negat(1, n);
		int L[m], R[m], cost[m];
		for(int i = 0; i < m; i++){
			cin >> L[i] >> R[i] >> cost[i];
			negat.push_back(R[i]);
			negat.push_back(L[i] - 1);
		}
		sort(negat.begin(), negat.end());
		while(q--){
			cin >> l >> r;
			for(int i = l - 1; i <= r - 1; i++){
				a[R[i]] -= cost[i];
				b[R[i]] -= cost[i];
				a[L[i] - 1] += cost[i];
				b[L[i] - 1] += cost[i];
			}
			int D = 0;
			for(int i = 0; i < negat.size() - 1; i++){
				if(negat[i] != negat[i+1])
					D += b[negat[i]];
				if(D < 0 && negat[i] != negat[i+1]){
					a[negat[i+1]] -= -D;
					a[negat[i]] += -D;
				}
			}
			for(auto i:negat)
				b[i] = 0;
		}
		for(int i = 1; i < n; i++)
			a[i] += a[i-1];
		for(int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
}