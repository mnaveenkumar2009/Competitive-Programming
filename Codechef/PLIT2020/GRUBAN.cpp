#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
    	int n, k;
    	cin >> n >> k;
    	int ans = -1;
    	for(int i = 1; i * i <= n; i++){
    		if(n%i == 0){
    			if(n/i >= (k * (k + 1))/2){
    				ans = max(ans, i);
    			}
    			if(i >= (k * (k + 1))/2){
    				ans = max(ans, n/i);
    			}
    		}
    	}
    	cout << ans << '\n';
    }
}