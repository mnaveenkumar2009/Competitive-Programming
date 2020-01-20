#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		bool we = 1;
		int n;
		cin >> n;

		int cur_freq[n], G[n + 1], a[n];
		multiset <int> avail_freq;

		for(int i = 0; i < n; i++)
			cur_freq[i] = G[i] = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] != -1)
				cur_freq[a[i]]++;
		}
		int XX = 0, YY = 0;
		for(int i = 0; i <= n; i++){
			cin >> G[i];
			XX += G[i];
			YY += G[i] * i;
			while(G[i]--){
				avail_freq.insert(i);
			}
			G[i] = 0;
		}
		if(XX != n)
			we = 0;
		if(YY != n)
			we = 0;
		// cout << n << "\n";
		// for(auto i :avail_freq)cout << i << ' ';cout << '\n';
		for(int i = n - 1; i >= 0; i--){
			auto it = avail_freq.lower_bound(cur_freq[i]);
			if(it == avail_freq.end()){
				we = 0;
				break;
			}
			G[i] = *it;
			avail_freq.erase(it);
		}
		if(we){
			int pointing = 0;
			for(int i = 0; i < n; i++){
				G[i] -= cur_freq[i];
				// cout << G[i] << ' ';
			}
			// cout << '\n';
			for(int i = 0; i < n; i++){
				if(!we)break;
				if(a[i] == -1){
					while(G[pointing] == 0){
						pointing++;
						if(pointing == n){
							we = 0;
							break;
						}
					}
					if(!we)break;
					a[i] = pointing;
					G[pointing]--;
				}
			}
			if(we){
				for(int i = 0; i < n; i++)cout << a[i] << ' ';cout << '\n';
			}
			else
				cout << "impossible\n";
		}
		else{
			cout << "impossible\n";
		}
	}	
}