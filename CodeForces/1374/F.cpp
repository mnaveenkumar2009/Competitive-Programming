#include <bits/stdc++.h>
using namespace std;

signed main(){
	int t;
	cin >> t;
	while(t--){
		int n, x = 0, y = 1;
		cin >> n;
		double a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			for(int j = 0; j < i; j++){
				if(a[j] > a[i])
					x++;
			}
		}
		for(int i = n - 1; (i >= 0) & y; i--){
			for(int j = i - 1; (j >= 0) & y; j--){
				if(a[j] == a[i] && (x&1)){
					a[j] = a[i] + 0.5;
					y = 0;
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(a[j] == a[i]){
					a[j] += 0.0001;
				}
			}
		}
		x = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++){
				if(a[j] > a[i])
					x++;
			}
		}
		if(x & 1)
			cout << "-1\n";
		else{
			vector <int> ans;
			for(int i = 0; i < n; i++){
				int pos = min_element(a + i, a + n) - a;
				while(pos != i){
					if(pos - i == 1){
						ans.push_back(i + 1);
						ans.push_back(i + 1);
						swap(a[i], a[i + 1]);
						swap(a[i + 1], a[i + 2]);
						pos = i;
					}
					else{
						ans.push_back(pos - 2 + 1);
						swap(a[pos], a[pos - 2]);
						swap(a[pos], a[pos - 1]);
						pos -= 2;
					}
				}
			}
			// for(auto j:a)cout << j <<' ';cout << '\n';
			cout << ans.size() << '\n';
			for(auto i:ans)cout << i << ' ';cout << '\n';
		}
	}
}