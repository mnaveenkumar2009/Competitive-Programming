#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n, T, a, b;
		cin >> n >> T >> a >> b;
		int tot = 0;
		pair <int, int> S[n];
		for(int i = 0; i < n; i++){
			cin >> S[i].second;
			tot += b * (S[i].second) + a * (1 - S[i].second);
		}
		for(int i = 0; i < n; i++){
			cin >> S[i].first;
		}
		if(tot <= T){
			cout << n << '\n';
			continue;
		}
		sort(S, S + n);
		int H[n], E[n];
		for(int i = 0; i < n; i++){
			// cout << S[i].first << ' ' << S[i].second << '\n';
			H[i] = (S[i].second == 1);
			E[i] = (S[i].second == 0);
			if(i){
				H[i] += H[i-1];
				E[i] += E[i-1];
			}
		}
		int ans = 0;
		int extra_tim = S[0].first - 1;
		if(extra_tim >= 0){
			int cur_ans = 0;
			int rem_easy = E[n-1], rem_hard = H[n-1];
			if(rem_easy * a <= extra_tim){
				cur_ans += rem_easy;
				extra_tim -= rem_easy * a;
				cur_ans += min(rem_hard, extra_tim / b);
			}
			else{
				cur_ans += extra_tim/a;
			}
			ans = max(ans, cur_ans);
		}
		for(int i = 0; i < n - 1; i++){
			if(S[i].first == S[i+1].first){
				continue;
			}
			// cout << "H E " << H[i] << ' '<< E[i] << '\n';
			int extra_tim = S[i+1].first - 1 - H[i] * b - E[i] * a;
			// cout << i << ' ' << extra_tim << '\n';
			if(extra_tim < 0){
				continue;
			}
			int cur_ans = i + 1;
			int rem_easy = E[n-1] - E[i], rem_hard = H[n-1] - H[i];
			if(rem_easy * a <= extra_tim){
				cur_ans += rem_easy;
				extra_tim -= rem_easy * a;
				cur_ans += min(rem_hard, extra_tim / b);
			}
			else{
				cur_ans += extra_tim/a;
			}
			ans = max(ans, cur_ans);
		}
		cout << ans << '\n';
	}
}