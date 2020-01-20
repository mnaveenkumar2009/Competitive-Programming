#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int PRIMROOT=3;

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;

void mlt(int &a,int b) { a=(ll)a*b%MOD; }
int pw(int x,int n) { int ret=1; while(true) { if(n&1) mlt(ret,x); if((n>>=1)==0) return ret; mlt(x,x); } }
 
struct NTT {
	void _init(int n,int &nlog,int &g,vector<int> &w) {
		assert((MOD - 1) % n == 0);
		g = pw(PRIMROOT, (MOD - 1) / n); nlog = 0; while ((1 << nlog) < n) ++nlog; if ((1 << nlog) != n) nlog = -1;
		w = vector<int>(n); w[0] = 1; FOR(i, 1, n) w[i] = (ll)w[i - 1]*g%MOD;
	}
	int fftn, fftnlog; int fftg; vector<int> fftw;
	void initfft(int n) { fftn = n, _init(fftn, fftnlog, fftg, fftw); assert(fftnlog != -1); }
	void fft(int *a, int n, bool inv) {
		if (n != fftn) initfft(n);
		for (int i = 1, j = n >> 1, k, l = j; i < n; j ^= k, ++i) { if (i < j) swap(a[i], a[j]); for (k = l; k&j; j ^= k, k >>= 1); }
		int *l, *r, *w;
		if (inv) reverse(fftw.begin() + 1, fftw.end());
		for (int hlen = 1, step = n >> 1; hlen < n; hlen <<= 1, step >>= 1) {
			for (int i = 0; i < n; i += (hlen << 1)) {
				l = a + i, r = l + hlen, w = fftw.data();
				REP(off, hlen) {
					int v = (ll)(*r)*(*w)%MOD;
					*r = (*l)-v; if(*r<0) *r+=MOD;
					*l = (*l)+v; if(*l>=MOD) *l-=MOD;
					++l, ++r, w += step;
				}
			}
		}
		if (inv) reverse(fftw.begin() + 1, fftw.end());
		if (inv) { int mlt = pw(n, MOD - 2); REP(i, n) a[i] = (ll)a[i]*mlt%MOD; }
	}
	void mult(const int *a,int na,const int *b,int nb,int *c,int nc) {
		int sz=1; while(sz<na+nb-1) sz*=2;
		vector<int> A(sz,0),B(sz,0);
		REP(i,na) A[i]=a[i]; REP(i,nb) B[i]=b[i];
		fft(A.data(),sz,false); fft(B.data(),sz,false); REP(i,sz) A[i]=(ll)A[i]*B[i]%MOD; fft(A.data(),sz,true);
		REP(i,nc) c[i]=i<sz?A[i]:0;
	}
};
 
NTT ntt;

vector<int> mult(const vector<int> &a,const vector<int> &b) {
	if(SZ(a)==0||SZ(b)==0) return vector<int>();
	vector<int> c(SZ(a)+SZ(b)-1,0);
	//REPSZ(i,a) REPSZ(j,b) c[i+j]=(c[i+j]+(ll)a[i]*b[j])%MOD;
	ntt.mult(a.data(),SZ(a),b.data(),SZ(b),c.data(),SZ(c));
	return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	string A, B;
	cin >> A >> B;
	int s[10], t[10];
	int costi = 0;
	for(int i = 0; i < 10; i++)
		cin >> s[i];
	for(int i = 0; i < 10; i++)
		cin >> t[i];
	int a[n + m - 1], cost[10][10];
	memset(a, 0, sizeof(a));
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			int c1 = 0, c2 = 0;
			int l = i, r = j;
			while(l != r){
				c1 += s[l];
				l = (l + 1) % 10;
			}
			l = i, r = j;
			while(l != r){
				c2 += t[r];
				r = (r + 1)%10;
			}
			cost[i][j] = min(c1, c2);
		}
	}

	for(int j = 0; j < 10; j++){
		vector <int> A1(n), B1(m);
		for(int i = 0; i < n; i++)
			A1[i] = cost[A[i]-'0'][j];
		
		for(int i = 0; i < m; i++)
			B1[i] = ((B[i]-'0') == j);
		reverse(B1.begin(), B1.end());
		vector <int> X = mult(A1, B1);
		for(int i = 0; i < n + m - 1; i++)
			a[i] += X[i];
	}
	int	ans = 1e9;
	for(int i = 0; i < (n - m + 1); i++)
		ans = min(ans, a[m - 1 + i]);	
	cout << ans << '\n';
}
