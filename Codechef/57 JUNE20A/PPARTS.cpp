// https://www.codechef.com/viewsolution/28193555 ntt code
#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
#define int long long

int pr(int A, int x){
	int ret = 1;
	while(x){
		if(x & 1){
			ret = (ret * A) % mod;
		}
		A = (A * A) % mod;
		x /= 2;
	}
    // cout << A << ' ' << x << ' ' << ret << '\n';
	return ret;
}
#define MOD 998244353
typedef long long ll;

ll pow_mod(ll x,int k) {
  ll ans=1;
  while (k) {
    if (k&1) ans=ans*x%MOD;
    x=x*x%MOD;
    k>>=1;
  }
  return ans;
}

const int Maxn=1<<20;

ll *w[20];

void ntt_init() {
  for(int i=2,t=0;i<=Maxn;i<<=1,t++) {
    w[t]=new ll[i>>1];
    ll wn=pow_mod(3,(MOD-1)/i);
    w[t][0]=1;
    for(int j=1;j<(i>>1);j++) w[t][j]=(w[t][j-1]*wn)%MOD;
  }
}

void rev(ll *p,int len) {
  int j=len>>1;
  for(int i=1;i<len-1;i++) {
    if (i<j) swap(p[i],p[j]);
    int k=len>>1;
    while (j>=k) {
        j-=k;
        k>>=1;
      }
    if (j<k) j+=k;
  }
}

void ntt(ll *p,int len,int check) {
  rev(p,len);
  for(int i=2,t=0;i<=len;i<<=1,t++)
    for(int j=0;j<len;j+=i)
      for(int k=j;k<j+(i>>1);k++) {
        ll u=p[k];
        ll v=w[t][k-j]*p[k+(i>>1)];
        p[k]=(u+v)%MOD;
        p[k+(i>>1)]=(u-v)%MOD;
      } 
  if (check==-1) {
    reverse(p+1,p+len);
    ll nev=pow_mod(len,MOD-2);
    for(int i=0;i<len;i++) p[i]=((p[i]+MOD)*nev)%MOD;
  }
}

vector <int> mult(vector <int> a, vector<int> b){
    int n2 = a.size();
    int m = b.size();
    int n = 1;
    while (n < n2 + m) 
        n <<= 1;
    int fa[n], fb[n];
    memset(fa, 0, sizeof(fa));
    memset(fb, 0, sizeof(fb));
    for(int i = 0; i < n2; i++)
        fa[i] = a[i];
    for(int i = 0; i < m; i++)
        fb[i] = b[i];

    ntt(fa, n, 1);
    ntt(fb, n, 1);
    for (int i = 0; i < n; i++)
        fa[i] = (fa[i] * fb[i]) % mod;
    ntt(fa, n, -1);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = fa[i];
    return result;
}
vector <int> minusonebyn(1000000, 0);
vector <int> exp_p(vector <int> h){
    int n = h.size(), m = 1;
    vector <int> f(1, 1), g(1, 1);
    while(m <= n/2){
        g.resize(m);
        if(m % 2==0){
            for(int i = m/2; i < m; i++)
                g[i] = 0;
        }
        vector <int> gsq = mult(g, g);
        gsq.resize(m);
        gsq = mult(gsq, f);
        gsq.resize(m);
        for(int i = 0; i < m; i++)
            g[i] = (2 * g[i] - gsq[i]) % mod;
        // g = 2 * g - f * g * g

        // q = h` of size m - 1
        vector <int> q(m - 1, 0);
        for(int i = 0; i < m - 1; i++){
            if(i + 1 < n)
                q[i] = (h[i+1] * (i  + 1)) % mod;
        }
        vector <int> w(2*m - 1, 0), ftemp = mult(f, q);
        for(int i = 0; i < ftemp.size(); i++){
            ftemp[i] = -ftemp[i];
            if(i < m - 1){
                ftemp[i] += (f[i+1] * (i + 1)) % mod;
            }
        }
        ftemp = mult(g, ftemp);
        ftemp.resize(2*m - 1);
        for(int i = 0; i < 2*m - 1; i++){
            w[i] = ftemp[i];
            if(i < m - 1){
                w[i] = (w[i] + q[i]) % mod;
            }
        }
        f.resize(2*m);
        for(int i = m; i < 2 * m; i++)f[i] = 0;
        vector<int> ftemp2(2*m);
        for(int i = 0; i < 2 * m; i++){
            ftemp2[i] = h[i];
            if(i)
                ftemp2[i] = (ftemp2[i] - w[i-1] * (mod - minusonebyn[i]))% mod;
        }
        ftemp2 = mult(ftemp2, f);
        ftemp2.resize(2 * m);
        for(int i = 0; i < 2 * m; i++)
            f[i] = (f[i] + ftemp2[i]) % mod;
        m = 2 * m;
    }
    return f;
}
signed main(){
    ntt_init();
    int n, q;
	cin >> n >> q;
    int N = log2(2*n + 1);
    N = (1 << N);
    if(N != n + 1)
        N <<= 1;

    int a[q], b[q];
    vector <int> A(N, 0);
    for(int i = 1; i < N; i++){
        minusonebyn[i] = mod - pr(i, mod - 2);
    }
	for(int i = 0; i < q; i++){
		cin >> a[i] >> b[i];
		b[i] = min(b[i], n/a[i]);
        // cout << b[i] << '\n';
        // a[i] * b[i] <= n .... a[i] * (b[i] + 1) <= 2*n
        A[a[i] * (b[i] + 1)]++;
        A[a[i]]--;
		// b[i]++; // number of elements
	}
    vector <int> H(N, 0);
    for(int i = 1; i < N; i++){
        for(int j = 1; j * i < N; j++){
            H[j*i] = (H[j*i] + minusonebyn[j] * (A[i])) % mod;
        }
    }
    vector<int> ans = exp_p(H);
    for(int i = 1; i <= n; i++)
        cout << (ans[i] + mod) % mod << ' '; cout << '\n';
}