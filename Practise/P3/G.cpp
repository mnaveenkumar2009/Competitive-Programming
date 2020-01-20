#include <bits/stdc++.h>
using namespace std;

#define ld long double

int main(){
	int n;
	ld x;
	cin >> n >> x;
	ld c[n];
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	sort(c, c + n);
	reverse(c, c + n);
	// (n/(n-k) + 1)*(x/2);
	ld ans = 0;
	int i;
	for(i = 0; i < n; i++){
		if((((ld)n/(ld)(n-(i+1)) + 1)*x)/2.0 <= c[i]){
			ans += (((ld)n/(ld)(n-(i+1)) + 1)*x)/2.0;
			cout << ans << '\n';
		}
		else
			break;
	}
	for(; i < n; i++){
		ans += c[i];
	}
	cout << ans << '\n';
}