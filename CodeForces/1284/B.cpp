#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int mini[n], maxi[n], l[n];
    vector <int> s[n], isI(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> l[i];
    	s[i].resize(l[i]);
    	maxi[i] = 0;
    	mini[i] = 1e9;
    	for(int j = 0; j < l[i]; j++){
    		cin >> s[i][j];
    		maxi[i] = max(maxi[i], s[i][j]);
    		mini[i] = min(mini[i], s[i][j]);
    		if(s[i][j] > mini[i]){
    			isI[i] = 1;
    		}
    	}
    	if(isI[i]){
    		maxi[i] = 1e12;
    		mini[i] = -2;
    	}
    }
    sort(maxi, maxi + n);
    int ans = 0;
    for(int i = 0; i < n; i++){
    	ans += n - (upper_bound(maxi, maxi + n, mini[i]) - maxi);
    }
    cout << ans << '\n';
}