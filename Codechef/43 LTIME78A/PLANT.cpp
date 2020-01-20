#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define p 31;

int n, inv[2000006];
string s;

int has(int i, int j){
	int ret = sum[j];
	if(i)
		ret -= sum[i - 1];
	ret *= inv[i];
	ret %= mod;
	ret += mod;
	return (ret % mod);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++){
    	sum[i] = (s[i] - '0') * pr(p, i);
    	sum[i] += sum[i-1];
    	sum[i] %= mod;
    }
    for(int i = 0; i < 2000006; i++)
    	inv[i] = pr(pr(p, i), mod - 2);
    for(int i = 0; i < n; i++){
    	
    }

}