#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n, m, k, t;
	cin >> n >> m >> k >> t;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	vector <pair <int, pair <int, int> > > traps(k);
	for(int i = 0; i < k; i++)
		cin >> traps[i].first >> traps[i].second.first >> traps[i].second.second;
	sort(traps.begin(), traps.end());

	int low = 0, high = n;
	while(low < high){
		int mid = (low + high) / 2;
		if(low == mid)mid++;
		int soldier = 0;
		if(mid != 0)
			soldier = a[mid - 1];
		// cout << mid << soldier << '\n';
		int time_taken = 0;
		vector <pair <int, int> > traps_that_matter;
		for(int i = 0; i < k; i++){
			if(traps[i].second.second > soldier)
				traps_that_matter.push_back({traps[i].first, traps[i].second.first});
		}
		if(traps_that_matter.size() == 0){
			low = mid;
			continue;
		}
		int prev_l = traps_that_matter[0].first, prev_r = traps_that_matter[0].second;
		for(auto i:traps_that_matter){
			// cout << i.first << ' ' << i.second << '\n';
			if(i.first > prev_r){
				time_taken += 2*(prev_r - prev_l + 1);
				prev_l = i.first;
				prev_r = i.second;
			}
			else
				prev_r = max(prev_r, i.second);			
		}
		time_taken += 2*(prev_r - prev_l + 1);
		// cout << mid << ' ' << time_taken + m + 1 << '\n';
		if(time_taken + m + 1 <= t)
			low = mid;
		else
			high = mid - 1;
	}
	cout << low << '\n';
}