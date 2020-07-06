#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int h, w, k, ans = 0;
	cin >> h >> w >> k;
	vector <string> s(h);
	for(int i = 0; i < h; i++){
		cin >> s[i];
	}
	for(int mask = 0; mask < 1 << (h + w); mask++){
		vector <string> t = s;
		for(int i = 0; i < h; i++){
			if(mask & (1<<i)){
				for(int j = 0; j < w; j++){
					t[i][j] = 'p';
				}
			}
		}
		for(int i = 0; i < w; i++){
			if(mask & (1<<(i + h))){
				for(int j = 0; j < h; j++){
					t[j][i] = 'p';
				}
			}
		}
		int xxx = 0;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				xxx += t[i][j] == '#';
			}
		}
		ans += xxx == k;
	}
	cout << ans << '\n';
}