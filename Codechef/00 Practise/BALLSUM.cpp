#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long

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

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

signed main(){
	int n, k, x, ans = 0;
	cin >> n >> k;
	int pre[n + 1];
	for(int i = 0; i <= n; i++)
		pre[i] = pr(i, k);
	vector <int> v[n];
	for(int i = 0; i < n; i++){
		cin >> x;
		v[x - 1].push_back(i);
	}
	for(int i = 0; i < n; i++){
		if(v[i].size() == 0)
			continue;
		int prev = -1;
		vector <int> a;
		for(auto j:v[i]){
			a.push_back(j - prev);
			prev = j;
		}
		a.push_back(n - prev);
		int S = a.size();
		vector<int> b = a;
		reverse(b.begin(), b.end());
		vector <int> res = multiply(a, b);
		for(int j = 0; j < v[i].size(); j++){
			res[j] %= mod;
			ans += res[j] * pre[S - 1 - j];
			ans %= mod;
		}
	}
	cout << ans << '\n';
}