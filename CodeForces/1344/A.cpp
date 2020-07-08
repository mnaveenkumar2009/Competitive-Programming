#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		set <int> X;
		for(int i = 0; i < n; i++){
		    int x;
		    cin >> x;
		    X.insert(((x + i)%n + n) % n);
		}
// 		cout << X.size() << '\n';/
		cout << ((X.size() - n) == 0? "YES":"NO") << '\n';
	}
}