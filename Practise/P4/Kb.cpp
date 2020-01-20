#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
signed main(){
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	while(q--){
		int c, l, r;
		cin >> c >> l >> r;
		l--;r--;
		if(c == 1){
			for(int i = l; i <= r; i++)
				s[i] = 'A' + 'B' - s[i];			
		}
		else{
			int a, b;
			cin >> a >> b;
			for(int i = l; i <= r; i++){
				if(s[i] == 'A'){
					a = (a + b) % mod;
				}
				else{
					b = (a + b) % mod;
				}
			}
			cout << a << ' ' << b << '\n';
		}
	}
}
