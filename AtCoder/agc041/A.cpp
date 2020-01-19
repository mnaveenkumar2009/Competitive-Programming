#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, a, b;
	cin >> n >> a >> b;
	if(a > b)
		swap(a, b);
	if(abs(a - b)&1){
		cout << min(1 + abs(a-b)/2 + min(a-1, n-b), min(b - 1, n - a));
	}
	else{
		cout << abs(a-b)/2 << '\n';
	}
}