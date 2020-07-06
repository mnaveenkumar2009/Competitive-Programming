#include <bits/stdc++.h>
using namespace std;

#define int long long
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n], ans = 0;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	for(int j = i; j < n; j++){
    		for(int k = j; k < n; k++){
    			ans = max(ans, (a[i] | a[j] | a[k]));
    		}
    	}
    }
    cout << ans << '\n';
}