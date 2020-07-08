#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t = 1;
	// cin >> t;
	while(t--){
		string s;
		cin >> s;
		int cur = 0, coun = 0;
		vector <pair <int, int> > v;
		for(auto i:s){
			if(i != cur){
				if(coun)
					v.push_back({cur, coun});
				cur = i;
				coun = 1;
			}
			else				
				coun++;
		}
				if(coun)
					v.push_back({cur, coun});

		// for(auto i:v){
			// cout <<  i.first << ' ' << i.second << '\n';
		// }
			int n = v.size();
		if((n & 1) == 0){
			cout << "0\n";
			return 0;
		}
		else{
			for(int i = 0; i < n; i++){
				if(v[i].first == v[n - i - 1].first){
					if(v[i].second + v[n-1-i].second < 3){
						cout << "0\n";
						return 0;
					}
				}
				else{
					cout << "0\n";
					return 0;
				}
			}
			cout << v[n/2].second + 1 << '\n';
		}
	}
}