#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t, n, a[1000006];
    cin >> t;
    while(t--){
	    cin >> n;
	    for(int i = 0; i < n; i++)
	    	cin >> a[i];
	    vector <int> done(n, 0), ans;
	    int cur = 0;
	    while(!done[cur]){
	    	ans.push_back(cur + 1);
	    	done[cur] = 1;
	    	cur -= a[cur];
	    }
	    for(int i = 0; i < ans.size(); i++){
	    	if(ans[i] == cur + 1){
	    		ans.erase(ans.begin(), ans.begin() + i);
	    		break;
	    	}
	    }
	    cout << ans.size() << '\n';
		for(auto i : ans)cout << i << ' ';cout << '\n';
	}
}