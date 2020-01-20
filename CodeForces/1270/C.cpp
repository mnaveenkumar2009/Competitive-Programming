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
    	int S = 0, X = 0;
    	for(int i = 0; i < n; i++){
    		int x;
    		cin >> x;
    		S += x;
    		X ^= x;
    	}
    	if( S == 2 * X){
    		cout << "0\n\n";
    		continue;
    	}
    	if(S + 1 == 2 * (X - 1)){
    		cout << "1\n1\n";
    		continue;
    	}
    	vector <int> ans(3, 0);
    	ans[0] = (1LL << 54);
    	if(S & 1){
    		ans[0] |= 1; 
    	}
    	S += ans[0];
    	X ^= ans[0];
    	ans[1] = ans[2] = X - S/2;
    	cout << "3\n";
    	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    }
}