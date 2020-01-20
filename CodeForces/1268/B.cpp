#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;
	std::vector<int> v;
	for(int i = 0; i < n; i++){
		if(v.size() != 0){
			if((v[v.size() - 1] - a[i])%2 == 0){
				ans += (a[i] + v[v.size() - 1])/2;
				v.pop_back();
			}
			else
				v.push_back(a[i]);
		}
		else
			v.push_back(a[i]);
	}
	for(auto i : v){
		ans += i/2;
	}
	cout << ans << '\n';
}