#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, x;
int dp[100005], p[100005], c[100005];

signed main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n >> x;
		for(int i = 0; i < n; i++){
			cin >> p[i];
			p[i]--;
			dp[i] = 1e18;
		}
		for(int i = 0; i < n; i++){
			cin >> c[i];
			c[i] = min(abs(p[i] - i) * x, c[i]);
		}

	    list<pair <int, int> > queue;
	    queue.push_back({0, 0});
	    while(!queue.empty()) 
	    {
	        auto s = queue.front();
	        queue.pop_front();
	        int i = s.first;
	        if(s.second > dp[i]){
	        	continue;
	        }
	        dp[i] = s.second;
	        if(i != n-1){
	            if (dp[i + 1] > x + dp[i]){
	                queue.push_back({i+1, dp[i] + x});
	            }
	            if (dp[p[i]] > c[i] + dp[i]){
	                queue.push_back({p[i], dp[i] + c[i]});
	            }
	            if(i != 0){
		            if (dp[i - 1] > x + dp[i]){
		                queue.push_back({i - 1, dp[i] + x});
		            }
	        	}
	        }
	    } 
		cout << dp[n-1] << '\n';
	}
}