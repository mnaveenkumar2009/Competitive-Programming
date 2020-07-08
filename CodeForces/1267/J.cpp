#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int F[n];
		memset(F, 0, sizeof(F));
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			F[x - 1]++;
		}
		vector <int> a;
		for(int i = 0; i < n; i++)
			if(F[i])
				a.push_back(F[i]);
		int N = a.size(), ans = 1e15;
		sort(a.begin(), a.end());
		// for(auto i:a){
		// 	cout << i << ' ';
		// }
		// cout << '\n';
		for(int s = 2; s <= a[0] + 1; s++){
			int curans = 0, we = 1;
			for(int i = 0; i < N; i++){
				if(a[i]/(s-1) >= a[i] % (s-1)){
					curans += a[i]/s + (a[i] % s != 0);
				}
				else{
					we = 0;
					break;
				}
			}
			if(we){
				// cout << curans << ' ' <<  s << '\n';
				ans = min(ans, curans);
			}
		}
		cout << ans << '\n';

	}
}