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
    	int n, x= 0, y = 0;;
    	cin >> n;
    	for(int i = 1; i <= n; i++){
    		if(i > n/2){
    			x += (1LL << i);
			}
			else{
				y += (1LL << i);
			}
		}
		x += (1LL << (n/2));
		x -= (1LL << (n));
		y -= (1LL << (n/2));
		y += (1LL << (n));
		cout << abs(x - y) << '\n';
    }
}