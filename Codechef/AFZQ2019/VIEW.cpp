#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin >> t;
    while(t--){
    	int x, y;
    	cin >> x >> y;
    	// x--;y--;
    	cout << max(x*y - x - y, 0LL) << '\n';
    }
}