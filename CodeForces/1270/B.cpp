#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	int a[n], b[n], maxi = -1e9, mini = 1e9;
    	set <pair <int, int > > X, Y;
    	for(int i = 0; i < n; i++){
    		cin >> a[i];
    		// maxi = max(a[i], maxi);
    		// mini = min(a[i], mini);
    		b[i] = a[i];
    		a[i] -= i;
    		b[i] -= n - i - 1;
    		X.insert({a[i], i});
    		Y.insert({b[i], n - i - 1});
    	}
    	bool we = 0;
    	for(int i = 0; i < n; i++){
    		auto it = X.lower_bound({a[i] + 1, 0});
    		if(it != X.end()){
    			cout << "YES\n";
    			cout << i + 1 << ' ' << it->second + 1 << '\n';
    			we = 1;
    			break;
    		}
    		X.erase({a[i], i});
    	}
    	if(!we){
	    	for(int i = n - 1; i >= 0; i--){
	    		auto it = Y.lower_bound({b[i] + 1, 0});
	    		if(it != Y.end()){
	    			// cout << "sd\n";
    				cout << "YES\n";
	    			cout << (n - it->second - 1) + 1 << ' ' << i + 1 << '\n';
	    			we = 1;
	    			break;
	    		}
	    		Y.erase({b[i], n - i - 1});
	    	}	
    	}
    	if(!we){
    		cout << "NO\n";
    	}
    }
}