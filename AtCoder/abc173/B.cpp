#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	map <string, int> M;
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		M[s]++;
	}
	cout << "AC x " << M["AC"] << '\n';
	cout << "WA x " << M["WA"] << '\n';
	cout << "TLE x " << M["TLE"] << '\n';
	cout << "RE x " << M["RE"] << '\n';
}