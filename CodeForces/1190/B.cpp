#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string ans[2] = {"sjfnb\n", "cslnb\n"};
	int n, sum = 0;
	cin >> n;
	int a[n];
	map <int, int> X;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		X[a[i]]++;
	}
	sort(a, a + n);
	int we = -1;
	for(int i = 0; i < n; i++){
		if(X[a[i]] > 2){
			cout << ans[1];
			return 0;
		}
		if(X[a[i]] == 2){
			if((a[i] == 0) || X[a[i] - 1] || (we != -1 && we != a[i])){
				// cout << "case 2 " << we << ' ';
				cout << ans[1];
				return 0;
			}
			we = a[i];
		}
		sum += a[i] - i;
	}
	// cout << "inc\n";

	if(sum & 1){
		cout << ans[0];
	}
	else{
		cout << ans[1];
	}
}