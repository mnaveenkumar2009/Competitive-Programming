#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    	string s;
    	cin >> s;
    	int n = s.size();

        vector<int> d1(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
		    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
		        k++;
		    }
		    d1[i] = k--;
		    if (i + k > r) {
		        l = i - k;
		        r = i + k;
		    }
		}

		vector<int> d2(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
		    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
		        k++;
		    }
		    d2[i] = k--;
		    if (i + k > r) {
		        l = i - k - 1;
		        r = i + k ;
		    }
		}
		int temp[n];
		memset(temp, 0, sizeof(temp));
		for(int i = 0; i < n; i++){
			// cout << d1[i] << ' ' << d2[i] << '\n';
			// d1[i] = min(d1[i], d1[i] * 2 - 1 + 2 * (i - (d1[i] - 1) + 1) <= n);
			if(i < (n + 1)/2)
				temp[(i - (d1[i] - 1))] = max(d1[i] * 2 - 1, temp[(i - (d1[i] - 1))]);
			if(2 * (i) <= n)
				temp[i - d2[i]] = max(temp[i - d2[i]], d2[i] * 2);
		}
		for(int i = 0; i < n; i++){
			if(i){
				temp[i] = max(temp[i-1] - 2, temp[i]);
			}
			// cout << temp[i] << ' ';
		}
		// cout << '\n';
		int maxi = 0, ans = -1;
		for(int i = 0; i <= (n)/2; i++){
			int cur = (i) * 2+ temp[i];
			if(cur > maxi){
				maxi = cur;
				ans = i;
			}
			if(s[i] != s[n - i - 1]){
				break;
			}
		}

		string ans1 = s.substr(0, ans) + s.substr(ans, temp[ans]) + s.substr(n - ans, ans);
		// cout << ans1 << '\n';
		reverse(s.begin(), s.end());
		{
			vector<int> d1(n);
			for (int i = 0, l = 0, r = -1; i < n; i++) {
			    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
			    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			        k++;
			    }
			    d1[i] = k--;
			    if (i + k > r) {
			        l = i - k;
			        r = i + k;
			    }
			}

			vector<int> d2(n);
			for (int i = 0, l = 0, r = -1; i < n; i++) {
			    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
			    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			        k++;
			    }
			    d2[i] = k--;
			    if (i + k > r) {
			        l = i - k - 1;
			        r = i + k ;
			    }
			}
			int temp[n];
			memset(temp, 0, sizeof(temp));
			for(int i = 0; i < n; i++){
				// cout << d1[i] << ' ' << d2[i] << '\n';
				// d1[i] = min(d1[i], d1[i] * 2 - 1 + 2 * (i - (d1[i] - 1) + 1) <= n);
				if(i < (n + 1)/2)
					temp[(i - (d1[i] - 1))] = max(d1[i] * 2 - 1, temp[(i - (d1[i] - 1))]);
				if(2 * (i) <= n)
					temp[i - d2[i]] = max(temp[i - d2[i]], d2[i] * 2);
			}
			for(int i = 0; i < n; i++){
				if(i){
					temp[i] = max(temp[i-1] - 2, temp[i]);
				}
				// cout << temp[i] << ' ';
			}
			// cout << '\n';
			int maxi = 0, ans = -1;
			for(int i = 0; i <= (n)/2; i++){
				int cur = (i) * 2+ temp[i];
				if(cur > maxi){
					maxi = cur;
					ans = i;
				}
				if(s[i] != s[n - i - 1]){
					break;
				}
			}
			string ans2 = s.substr(0, ans) + s.substr(ans, temp[ans]) + s.substr(n - ans, ans);
			if(ans1.size() < ans2.size())
				ans1 = ans2;
		}
		cout << ans1 << '\n';
    }
}