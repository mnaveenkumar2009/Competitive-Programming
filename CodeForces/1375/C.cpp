#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		vector <int> v;
		for(int i = 0; i < n; i++){
		    if(v.size() == 0){
		        v.push_back(a[i]);
		    }
		    else{
		        while(v.size() != 1){
		            if(v[v.size() - 1] < a[i]){
		                v.pop_back();
		            }
		            else{
		                break;
		            }
		        }
		        if(v.size() == 1 && v[0] < a[i]){
		            
		        }
		        else{
		            v.push_back(a[i]);
		        }
		    }
		}
		if(v.size() == 1){
		      cout << "YES\n";
		}
		else
		    cout << "NO\n";
	}
	return 0;
}