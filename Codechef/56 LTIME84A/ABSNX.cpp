#include <bits/stdc++.h>
using namespace std;
#define int long long

int nge[250000], nle[250000], a[250000], n;
void pre() {
	stack <pair <int, int> > s;
	s.push({a[0], 0});
	for(int i = 1; i < n; i++){ 
	    if(s.empty()){
			s.push({a[i], 1});
			continue; 
	    }
	    while (s.empty() == false && (s.top()).first < a[i]) {
	        nge[s.top().second] = i;
	        s.pop(); 
	    }
    	s.push({a[i], i}); 
  	}
	while (s.empty() == false) { 
		nge[s.top().second] = n;
		s.pop(); 
	}
	s.push({a[0], 0});
	for(int i = 1; i < n; i++){ 
	    if(s.empty()){
			s.push({a[i], 1});
			continue; 
	    }
	    while (s.empty() == false && (s.top()).first > a[i]) {
	        nle[s.top().second] = i;
	        s.pop(); 
	    }
    	s.push({a[i], i}); 
  	}
	while (s.empty() == false) { 
		nle[s.top().second] = n;
		s.pop(); 
	}
} 

int dp[250001][2];
int f(int i, bool x){
	if(dp[i][x] != -1){
		return dp[i][x];
	}
	if(x){
		if(nge[i] != -1 && (nge[i] <= nle[i] || nle[i] == -1))
			return dp[i][x] = 1 + f(nge[i], 1);
		else{
			return dp[i][x] = 1;
		}
	}
	else{
		if(nle[i] != -1 && (nle[i] <= nge[i] || nge[i] == -1))
			return dp[i][x] = 1 + f(nle[i], 0);
		else{
			return dp[i][x] = 1;
		}
	}
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	memset(dp, -1, sizeof(dp));
    	cin >> n;
    	int FF[n];
    	for(int i = 0; i < n; i++){
    		cin >> a[i];
    	}
    	pre();
    	int i = 0;
    	while(i < n){
    		int j = i;
    		while(a[j] == a[i]){
    			j++;
    			if(j == n)break;
    		}
    		// ans += ((j - i) * (j - i + 1)) / 2;
    		for(int k = i; k < j; k++)
    			FF[k] = j - k;
    		i = j;
    	}
    	// for(int i = 0; i < n; i++){
    	// 	cout << nge[i] << ' ' << nle[i] << '\n';
    	// }
    	int ans = 0;
    	for(i = 0; i < n; i++){
    		for(int j = i; j < nge[i]; j = nle[j]){
    			ans+=FF[j];
    		}
    		// cout << i << ' ' << ans << '\n';
    		for(int j = i; j < nle[i]; j = nge[j]){
    			ans+=FF[j];
    		}
    		// cout << i << ' ' << ans << '\n';
    		ans -= FF[i];
    		// cout << nle[i] << ' ' << nge[i] << '\n';
    		// cout << i << ' ' << ans << '\n';
    		// cout << f(i, 0)  << ' ' <<  f(i, 1) << '\n';
    	}
    	// cout << ans << '\n';

    	cout << ans << '\n';
    }
}