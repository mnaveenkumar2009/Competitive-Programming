#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		if(a>b)
			swap(a, b);
		if((b - a) <= a){
			int tmp = b - a;
			b -= 2*(tmp);
			a -= tmp;
		}
		// cout << a << ' '<<b<<'\n';
		if(a==b && b%3==0)
			cout << "YES\n";
		else{
			cout <<"NO\n";
		}
	}
}