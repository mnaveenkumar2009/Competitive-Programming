#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s[n], s2[m];
    for(int i = 0; i < n; i++)
    	cin >> s[i];
    for(int i = 0; i < m; i++)
    	cin >> s2[i];
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		x--;
		cout << s[x%n] + s2[x%m] << '\n';
	}	
}