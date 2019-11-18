#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define mod 1000000007
ll pr(ll x, ll y)
{
    ll res = 1; 
    x = x % mod;
    while (y > 0){
        if (y & 1)
            res = (res*x) % mod;
        y >>= 1;
        x = (x*x) % mod;  
    }
    return res;
}
signed main(){
	vector <int> fact(3000006), invfact(3000006);
	fact[0] = 1;
	invfact[0] = 1;
	for(int i = 0; i < 3000003; i++){
		fact[i+1] = (fact[i] * (i+1))%mod;
		invfact[i+1] = pr(fact[i+1], mod - 2);
	}
	int x, y;
	cin >> x >> y;
	if(x > y)
		swap(x, y);
	int Y = y - x;
	int X = (x - Y)/3;
	if((x - Y)%3 || X < 0 || Y < 0){
		cout << "0\n";
		return 0;
	}
	// cout << X <<' ' << Y << '\n';
	int no_of_steps = 2 * X + Y;
	int ans = 1;
	ans *= fact[2*X + Y];
	ans %= mod;
	ans *= invfact[X + Y];
	ans %= mod;
	ans *= invfact[X];
	ans %= mod;
	cout << ans << '\n';
}