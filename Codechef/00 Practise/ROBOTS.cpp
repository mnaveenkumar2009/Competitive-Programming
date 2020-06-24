#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
const ld pi = atan(1) * 4;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	// cout << pi << '\n';
	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		vector< std::vector<int> > c(n, std::vector<int> (6, 0));
		int curr[n];
		int cur = 0;
		for(int i = 0; i < n; i++){
			c[i][(cur + s[i] - '0')%6]++;
			// cout <<((cur + s[i] - '0')%6) << '\n';
			cur += s[i] - '0';
			cur %= 6;
			curr[i] = cur;
		}
		for(int i = 1; i < n; i++){
			for(int j = 0; j < 6; j++){
				c[i][j] += c[i-1][j];
			}
		}
		while(q--){
			int l, r;
			cin >> l >> r;
			l--;r--;
			vector <int> C = c[r];
			// for(int j = 0; j < 6; j++){
			// 	cout << C[j] <<' ';
			// }cout << '\n';
			if(l){
				int cur = curr[l-1];
				// cout << cur << '\n';
				cur %= 6;
				// cout << cur << '\n';
				for(int j = 0; j < 6; j++){
					C[j] -= c[l-1][j];
					// cout << C[j] <<' ';
				}
				vector<int> D = C;
				for(int j = 0; j < 6; j++){
					C[j] = D[(j + cur)%6];
					// cout << C[j] <<' ';
				}

			}
			ld x = 0, y = 0;
			x += C[0] - C[3];
			y += (C[2] - C[5] + C[1] - C[4])* (cos(pi/6.0));
			x += (C[1] + C[5] - C[2] - C[4])*cos(pi/3.0);
			cout << fixed << setprecision(9) << x <<' ' << y << '\n';
		}
	}
}