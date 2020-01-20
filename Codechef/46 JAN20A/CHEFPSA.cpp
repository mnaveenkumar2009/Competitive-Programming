#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

vector <int> fact(2000006, 1);

int pr(int x, int y) {
    int res = 1;
    x = x % mod;
    while (y > 0){
        if (y & 1)
            res = (res*x) % mod;
        y >>= 1;
        x = (x*x) % mod;
    }
    return res;
}

int solve(){
	int n;
	cin >> n;
	n *= 2;
	vector <int> a(n);
	map <int, int> X, Y;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		X[a[i]]++;
	}
	sort(a.begin(), a.end());
	int S = a[n-1];
	if(X[a[2] + a[n-1]])
		S = a[2] + a[n-1];
	if(X[a[0] + a[n-1]])
		S = a[0] + a[n-1];
	if(X[S] < 2)
		return 0;
	for(int i = 0; i < n; i++){
		if(a[i] == S){
			a.erase(a.begin() + i, a.begin() + i + 2);
			break;
		}
	}
	n -= 2;
	for(int i = 0; i < n; i++){
		if(a[i] + a[n-i-1] != S)
			return 0;
	}
	X[S] -= 2;
	int tot = 0, ret = 1;
	Y = X;
	for(auto num : X){
		int x = num.first, y = num.second;
		if(!y)continue;
		if(x > S - x)
			continue;
		if(x == S - x){
			if(y&1)
				return 0;
			tot += y/2;
			ret = (ret * pr(fact[y/2], mod - 2)) % mod;
			continue;
		}
		if(Y[S-x] != y)
			return 0;
		tot += y;
		ret = (ret * pr(fact[y], mod - 2)) % mod;
		ret = (ret * pr(2, y)) % mod;
	}
	ret *= fact[tot];
	assert(ret >= 0);
	return ret % mod;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin >> t;
	for(int i = 1; i < 2000006; i++){
		fact[i] = (fact[i-1] * i) % mod;
	}
	while(t--)
		cout << solve() << '\n';
}