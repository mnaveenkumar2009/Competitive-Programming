#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, c;
    cin >> n;
    int a[2] = {0, 0};
    cin >> m >> c;
    while(n--){
    	int x, y, p;
    	cin >> x >> y >> p;
    	if(y - m * x - c >= 0){
    		a[0] += p;
    	}
    	if(y - m * x - c <= 0){
    		a[1] += p;
    	}
    }
    cout << max(a[0], a[1]) << '\n';
}