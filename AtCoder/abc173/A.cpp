#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() {
	int n;
	cin >> n;
	cout << (1000 - (n % 1000))%1000;
}
