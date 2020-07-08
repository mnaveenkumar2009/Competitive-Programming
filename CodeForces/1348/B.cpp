#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    
    while(t--){
    	int n, x= 0, y = 0, k;
    	set <int> X;
    	cin >> n >> k;
    	for(int i = 0; i < n; i++){
			cin >> x;
			X.insert(x);
		}
		int i = 1;
		while(X.size() < k){
			X.insert(i);
			i++;
		}
		if(X.size() != k){
			cout << "-1\n";
			continue;
		}
    	cout << n * k << '\n';
    	for(i = 0; i < n; i++){
    		for(auto j:X)cout << j << ' ';
		}cout << '\n';
    }
}