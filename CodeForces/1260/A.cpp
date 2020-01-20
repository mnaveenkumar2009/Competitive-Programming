#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin >> t;
	while(t--){
		int c, sum, ans=0;
		cin >> c >> sum;
		int x = sum/c;
		vector <int> a(c, x);
		sum -= x*c;
		for(int i = 0; i < c; i++){
			if(sum){
				a[i]++;
				sum--;
			}
			ans += a[i]*a[i];
		}
		cout << ans << '\n';
	}
}