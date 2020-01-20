#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
const int MAXPOW3 = pow(3, 11);
int conv(int n){
    int ret = 0;
    for(int i = 10; i >= 0; i--)
        if((n >> i)&1)
            ret += pow(3, i);
    return ret;
}
// dft template for convolution with xor base 3 https://www.codechef.com/viewsolution/15686863
typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;
#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int A = 100010;
vll d2i;
ll invk[12];
vll d2;
vvi dk(11);
ll a[1000000][3];
ll temp[3][3];
int to[3][3];
int ito[3][3];
int k = 3;

void dft1(const vector<ll*> & x, int inv) {
    forn(i,0,3) forn(j,0,3) temp[i][j] = 0;
    forn(i,0,3) forn(deg,0,3) {
        int s;
        if(inv) s = to[i][deg];
        else s = ito[i][deg];
        forn(j,0,3) temp[deg][(s+j)%3] += x[i][j];
    }
    if(inv) forn(i,0,3) forn(j,0,3) x[i][j] = (temp[i][j] * invk[3]) % mod;
    else forn(i,0,3) forn(j,0,3) x[i][j] = temp[i][j] % mod;
}

void dft(int N, int inv) {
    int cdk = 1;
    while(cdk < N) {
        int cur = 0;
        while(cur<N) {
            forn(it,0,cdk) {
                vector<ll*> proc;
                forn(st,0,k) proc.pb(&a[cur + cdk*st][0]);
                dft1(proc, inv);
                cur++;
            }
            cur += cdk*(k-1);
        }
        cdk *= k;
    }
}

ll powM(ll x, ll y, ll modulo) {
    ll res = 1; 
    x = x % modulo;
    while (y > 0){
        if (y & 1)
            res = (res*x) % modulo;
        y >>= 1;
        x = (x*x) % modulo;  
    }
    return res;
}

vll mul(const vll & a, const vll & b) {
    vll c(3,0);
    forn(i,0,3) forn(j,0,3) c[(i+j)%3] += a[i]*b[j];
    forn(i,0,3) c[i]%=mod;
    return c;
}

void powdo(ll * a, ll d) {
    vll res(k,0);
    res[0] = 1;
    vll md;
    forn(i,0,k) md.pb(a[i]);
    while(d>0) {
        if(d%2) res = mul(res, md);
        d /= 2;
        md = mul(md, md);
    }
    forn(i,0,k) a[i] = res[i];
}

typedef complex <ld> C;
const C I(0,1);
vector <int> prime;
void Sieve(){
    vector <bool> done(1e6, 0);
    for(int i = 2; i < 1e6; i++){
        if(!done[i]){
            prime.push_back(i);
            for(int j = 2; i*j < 1e6; j++)
                done[j*i] = 1;
        }
    }
}
#define LL long long
bool isprime(LL n){
    if(n<2) return false;
    for(int it=0;it<10;++it){
        LL i = rand()%(n-1)+1;
        if(__gcd(i,n)!=1) return false;
        if(powM(i,n-1,n)!=1) return false;
    }
    return true;
}

int cd(int n) {
    if (n == 1) 
        return 1;
    int ans = 1;
    for (int i = 0;(prime[i] * prime[i] * prime[i] <= n) ; i++) {
        int cnt = 1;
        while (n % prime[i] == 0){ 
            n = n / prime[i]; 
            cnt++;
        }
        ans = ans * cnt; 
    }
    bool we = 0;
    int sq = sqrt(n);
    if(sq*sq == n){
        we = (lower_bound(prime.begin(), prime.end(), sq) != prime.end());
    }
    if(n == 1)
        return ans;
    if (isprime(n))
        ans = ans * 2;
    else if (we) 
        ans = ans * 3;
    else if (n != 1)
        ans = ans * 4;
    return ans;
} 
signed main(){
    Sieve();
    forn(i,2,12) {
        ll cur = 1;
        while(cur%i!=0) cur+=mod;
        invk[i] = cur/i;
    }
    int i2 = (mod+1)/2;
    ll cur = 1;
    ll c2 = 1;
    forn(i,0,A) {
        d2i.pb(cur);
        cur = (cur*i2)%mod;
        d2.pb(c2);
        c2=(c2*2)%mod;
    }
    forn(bb,2,11) {
        int cb = 1;
        while(cb<A*bb) {
            dk[bb].pb(cb);
            cb*=bb;
        }
    }
    int t;
    cin >> t;
    while(t--){
        forn(i,0,1000000) forn(j,0,3) a[i][j] = 0;
        forn(i,0,3) 
            forn(j,0,3){
                to[i][j] = (i*j)%3;
                ito[i][j] = (k-to[i][j])%3;
            }
        int n, x;
        cin >> n >> x;
        while(n--){
            int xx, temp = -1;
            cin >> xx;
            // for(int i = 1; i*i <= xx; i++)
            //     if(xx % i == 0)
            //         temp += 2;
            // temp -= ((int)sqrt(xx) * (int)sqrt(xx)) == xx;
            temp = cd(xx) - 1;
            a[conv(temp)][0]++;
        }
        if(x > 12)
        continue;
        int N = MAXPOW3;
        dft(N, 0);
        forn(i,0,N) powdo(a[i], x);
        dft(N, 1);
        ld PI = acos((ld) -1.);
        ll ans = 0;
        forn(i,1,N) {
            C res = 0;
            forn(j,0,3) 
                res += exp(2*j*PI/k*I)*ld(a[i][j]);
            while(res.real() < 0) res+=mod;
            ll val = (ll(res.real()+0.5) % mod + mod)%mod;
            ans = (ans + val)%mod;
        }
        cout << ans << '\n';
    }
}