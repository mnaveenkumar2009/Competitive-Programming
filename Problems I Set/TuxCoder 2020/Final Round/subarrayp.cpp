#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
 
using namespace std;
 
#define int long long
#define mod MOD

#define fst first
#define snd second
#define mp make_pair
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
 
typedef long long ll;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef long double ld;
typedef complex<ld> cd;
typedef vector<cd> vcd;
 
const ld EPS = 1e-9;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const ld PI = acos(-1.0);

void addmod(int& x, int y, int mod) {
  (x += y) >= mod && (x -= mod);
}
 
int mulmod(int x, int y, int mod) {
  return x * 1ll * y % mod;
}

namespace FFT {
  struct cd {
    ld a, b;
 
    cd(ld a, ld b) : a(a), b(b) {}
 
    cd(ld x = 0) : a(x), b(0) {}
 
    ld real() const {
      return a;
    }
 
    void operator += (const cd& other) {
      a += other.a;
      b += other.b;
    }
 
    void operator -= (const cd& other) {
      a -= other.a;
      b -= other.b;
    }
 
    void operator *= (const cd& other) {
      tie(a, b) = mp(a * other.a - b * other.b, a * other.b + b * other.a);
    }
 
    friend cd operator * (const cd& x, const cd& y) {
      cd r = x;
      r *= y;
      return r;
    }
 
    friend cd operator + (const cd& x, const cd& y) {
      cd r = x;
      r += y;
      return r;
    }
 
    friend cd operator - (const cd& x, const cd& y) {
      cd r = x;
      r -= y;
      return r;
    }
 
    void operator /= (ld c) {
      a /= c;
      b /= c;
    }
  };
 
  typedef vector<cd> vcd;
 
  const int LOG = 15;
  const int N = 1 << LOG;
 
  int rev[N];
  cd root_[N];
 
  inline cd root(int k, int n) {
    return root_[k * (N / n)];
  }
 
  void precalc() {
    rev[0] = 0;
    int hb = -1;
    for (int i = 1; i < N; ++i) {
      if  ((i & (i - 1)) == 0) {
        ++hb;
      }
      rev[i] = rev[i ^ (1 << hb)] | (1 << (LOG - hb - 1));
    }
 
    forn(i, N) {
      ld ang = PI * i * 2.0 / N;
      root_[i] = cd(cosl(ang), sinl(ang));
    }
  }
 
  void fft_rec(cd* a, int n) {
    if  (n == 1) {
      return;
    }
 
    fft_rec(a, n / 2);
    fft_rec(a + n / 2, n / 2);
   
    forn(k, n / 2) {
      cd w = root(k, n);
      cd x = a[k];
      cd y = w * a[k + n / 2];
      a[k] = x + y;
      a[k + n / 2] = x - y;
    }
  }
 
  void fft(vcd& a) {
    int n = sz(a);
    vcd na(n, cd(0, 0));
    forn(i, n) na[i] = a[rev[i]];
    na.swap(a);
 
    fft_rec(&a[0], n);
  }
 
  void fft_inv(vcd& a) {
    fft(a);
    int n = sz(a);
    reverse(a.begin() + 1, a.end());
    forn(i, n) {
      a[i] /= n;
    }
  }
 
  vi mult(const vi& a, const vi& b) {
//    TimeStamp t("mult");
    vcd A(N, cd(0, 0));
    vcd B(N, cd(0, 0));
    forn(i, sz(a)) A[i] = a[i];
    forn(i, sz(b)) B[i] = b[i];
 
    fft(A);
    fft(B);
 
    forn(i, N) A[i] *= B[i];
 
    fft_inv(A);
 
    vi c(N, 0);
    forn(i, N) c[i] = ((ll) (A[i].real() + 0.5)) % MOD;
 
    return c;
  }
 
  vi multmod(const vi& a, const vi& b) {
    // a = a0 + sqrt(MOD) * a1
    // a = a0 + base * a1
    int base = (int) sqrtl(MOD);
   
    vi a0(sz(a)), a1(sz(a));
    forn(i, sz(a)) {
      a0[i] = a[i] % base;
      a1[i] = a[i] / base;
      assert(a[i] == a0[i] + base * a1[i]);
    }
 
    vi b0(sz(b)), b1(sz(b));
    forn(i, sz(b)) {
      b0[i] = b[i] % base;
      b1[i] = b[i] / base;
      assert(b[i] == b0[i] + base * b1[i]);
    }
 
    vi a01 = a0;
    forn(i, sz(a)) {
      addmod(a01[i], a1[i], MOD); 
    }
 
    vi b01 = b0;
    forn(i, sz(b)) {
      addmod(b01[i], b1[i], MOD);
    }
 
    vi C = mult(a01, b01);  // 1
 
    vi a0b0 = mult(a0, b0); // 2
    vi a1b1 = mult(a1, b1); // 3
   
    vi mid = C;
    forn(i, N) {
      addmod(mid[i], -a0b0[i] + MOD, MOD);
      addmod(mid[i], -a1b1[i] + MOD, MOD);
    }
 
    vi res = a0b0;
    forn(i, N) {
      addmod(res[i], mulmod(base, mid[i], MOD), MOD);
    }
 
    base = mulmod(base, base, MOD);
    forn(i, N) {
      addmod(res[i], mulmod(base, a1b1[i], MOD), MOD);
    }
     
    return res;
  }
};

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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    vector <int> A(2 * n), B(2 * n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i)
            a[i] *= a[i-1];
        a[i] %= mod;
        A[i] = (a[i] * pr(i + 1, mod - 2)) % mod;
        B[i] = (pr(a[i], mod - 2) * pr(i + 2, mod - 2)) % mod;
    }
    reverse(B.begin(), B.begin() + n);
    FFT::precalc();
    vector <int> C = FFT::multmod(A, B);
    
    // B[i - j + 1] = sum(ai * aj * 1/i  *1/j for all i > j)

    for(int i = n; i < 2 * n; i++){
        C[i] += (A[i - n]) % mod;
        C[i] %= mod;
    }
    for(int i = n; i < 2*n; i++){
        cout << C[i] << ' ';
    }
    cout << '\n';
}