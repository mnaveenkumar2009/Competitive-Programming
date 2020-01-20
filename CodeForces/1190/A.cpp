#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int a[m];
	for(int i = 0; i < m ; i++)
		cin >> a[i];
	sort(a, a + m);
	int removed = 0, cur = 0, ans = 0;
	while(1){
		int boun = (((a[cur] - removed - 1)/k + 1) * k) - (a[cur] - removed);
		// cout << cur << ' ' << boun << '\n';
		int pos = lower_bound(a, a + m, a[cur] + boun) - a;
		if(pos == m){
			pos--;
		}
		if(a[pos] > a[cur] + boun)
			pos--;
		ans++;
		removed += pos - cur + 1;
		cur = pos + 1;
		if(cur >= m)
			break;
	}
	cout << ans << '\n';
}