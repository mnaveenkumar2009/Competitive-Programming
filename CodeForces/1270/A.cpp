#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n, k1, k2;
    	cin >> n >> k1 >> k2;
    	string ans = "YES\n";
    	for(int i = 0;i < k1; i++){
    		int x;
    		cin >> x;
    		if(x == n){
    			// ans = ";
    		}
    	}
    	for(int i = 0;i < k2; i++){
    		int x;
    		cin >> x;
    		if(x == n){
    			ans = "NO\n";
    		}
    	}
    	cout << ans;
    }
}