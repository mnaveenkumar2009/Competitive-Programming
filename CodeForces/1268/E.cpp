#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e9
int a[2000005], n;

int f(int i, bool x){
	if(i < 0 || i >= n)
		return INF;
	if(x == (a[i]&1))
		return dp[i][x] = 0;
	return  dp[i][x] = f(i + a[i], x);
}

signed main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector< pair <int, int> > v;
	for(int i = 0; i < n; i++){
		v.push_back({i, {a[i]&1, }})
	}
}