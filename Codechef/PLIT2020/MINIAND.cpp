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
    	vector <int> a;
    	for(int i = 0; i < n; i++){
    		int x;
    		cin >> x;
    		if(x&1){
    			a.push_back(i+1);
    		}
    	}
    	int q;
    	cin >> q;
    	while(q--){
    		int l, r;
    		cin >> l >> r;
    		int le = lower_bound(a.begin(), a.end(), l) - a.begin(), re = lower_bound(a.begin(), a.end(), r) - a.begin();
    		bool we = 1;
    		if(le == a.size() || re == a.size()){
    			we = 0;
    		}
    		else{
    			if(re - le != r - l)
    				we = 0;
    			if(a[le] != l || a[re] != r)
    				we =0;
    		}
    		if(we){
    			cout << "ODD\n";
    		}
    		else{
    			cout << "EVEN\n";
    		}
    	}
    }
}