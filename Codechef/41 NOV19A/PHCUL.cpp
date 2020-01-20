#include <bits/stdc++.h>
using namespace std;

#define ld long double
ld dist(ld x1, ld y1, ld x2, ld y2){
	ld ret = (x1 - x2)*(x1 - x2) + (y1 - y2) * (y1 - y2);
	return sqrt(ret);
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int x, y, n, m, k;
		ld ans = 1e17;
		cin >> x >> y >> n >> m >> k;
		int a[n][2], b[m][2], c[k][2];
		vector <ld> minia(n, 1e17), minib(m, 1e17);
		for (int i = 0; i < n; ++i)
			cin >> a[i][0] >> a[i][1];

		for (int i = 0; i < m; ++i)
			cin >> b[i][0] >> b[i][1];

		for (int i = 0; i < k; ++i)
			cin >> c[i][0] >> c[i][1];

		for(int i = 0; i < n; i++)
			for(int j = 0; j < k; j++)
				minia[i] = min(minia[i], dist(a[i][0], a[i][1], c[j][0], c[j][1]));

		for(int i = 0; i < m; i++)
			for(int j = 0; j < k; j++)
				minib[i] = min(minib[i], dist(b[i][0], b[i][1], c[j][0], c[j][1]));

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				ans = min(ans, dist(a[i][0], a[i][1], x, y) + dist(b[j][0], b[j][1], a[i][0], a[i][1]) + minib[j]);
				ans = min(ans, dist(b[j][0], b[j][1], x, y) + dist(b[j][0], b[j][1], a[i][0], a[i][1]) + minia[i]);
			}
		}
		cout << fixed << setprecision(9) << ans << '\n';
	}
}