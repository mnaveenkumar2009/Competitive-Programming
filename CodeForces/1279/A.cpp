#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int a[3];
		cin >> a[0] >>a[1] >> a[2];
		sort(a, a + 3);
		if(a[2] - 1 > a[1] + a[0]){
			cout << "No\n";
		}
		else{
			cout << "Yes\n";
		}
	}	
}