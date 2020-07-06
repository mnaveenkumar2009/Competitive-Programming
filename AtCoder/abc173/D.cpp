#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int n;
	cin >> n;
	int a[n], sum = 0;
	for(int i =0 ; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	sum = a[n-1];
	for(int i = 0; i < n-2; i++){
		sum += a[n-2-i/2];
	}
	cout << sum << '\n';
}