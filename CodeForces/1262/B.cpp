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
		set <int> S;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			S.insert(i + 1);
		}
		vector <int> b(n, -1);
		b[0] = a[0];
		S.erase(a[0]);
		for(int i = n-2; i >= 0; i--){
			if(a[i] != a[i+1]){
				b[i+1] = a[i+1];
				S.erase(a[i+1]);
			}
		}
		for(int i = 0; i < n; i++){
			if(b[i] == -1){
				b[i] = *S.begin();
				S.erase(S.begin());
			}
		}
		bool we = 1;
		for(int i = 1; i < n; i++){
			if(a[i] != max(a[i-1], b[i])){
				we = 0;
				break;
			}
		}
		if(we){
			for(auto i:b)
				cout << i << ' ';cout << '\n';
		}
		else
			cout << "-1\n";
	}
}
