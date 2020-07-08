#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, a, r, m;
int h[100005];

int f(int x){
	int noi = 0, nod = 0;
	for(int i = 0; i < n; i++){
		if(h[i] >= x){
			nod += h[i] - x;
		}
		else{
			noi += x - h[i];
		}
	}
//	cout << x << ' ' << noi << ' ' << nod << '\n';
	if(noi > nod){
		return (noi - nod) * a + nod * m;
	}
	else{
		return (nod - noi) * r + noi * m;
	}
}
signed main(){
	cin >> n >> a >> r >> m;
	m = min(m, a + r);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	sort(h, h + n);
	int low = h[0], high = h[n-1];
//	for(int ind = low; ind <= high; ind++){
//		cout << f(ind) << '\n';
//	}
	int ans = 1e18;
	while(high - low >= 5){
		int mid1 = low + (high - low)/3;
		int mid2 = low + ((high - low) * 2)/3;
		int x1 = f(mid1) , x2 = f(mid2);
		if(x1 > x2){
			low = mid1;
		}
		if(x2 > x1){
			high = mid2;
		}
		if(x2 == x1){
			ans = min(ans, f(low));
			ans = min(ans, f(high));
			ans = min(ans, x1);
			low = high = mid1;
			break;
		}
	}
	for(int ind = low; ind <= high; ind++){
		ans = min(ans, f(ind));
	}
	cout << ans;
}