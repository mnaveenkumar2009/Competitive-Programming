#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007
int p1 = 31, p2 = 97;

int pr(int x, int y){
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
signed main(){
	int t;
	cin >> t;
	while(t--){
		string a, b, c;
		vector <int> A1(a.size()), B1(b.size()), C1(c.size());
		vector <int> A2(a.size()), B2(b.size()), C2(c.size());
		cin >> a >> b >> c;
		for(int i = 0; i < a.size(); i++){
			A1[i] = (a[i] - '0') * p1;
			A2[i] = (a[i] - '0') * pr(p2, );
		}
	}
}