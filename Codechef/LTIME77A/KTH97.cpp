#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

inline ll fpow(ll n, ll k) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = (r * n)% mod; n = (n * n) % mod;} return r;}

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)


typedef long long LL;
typedef double db;

const int mo = 1e9+7;
const int MAXN = (1<<19)+5;
const int maxn = (1<<19);
const db pi = acos(-1);
const int Blk = 31623;

LL quickmi(LL x,LL tim){
    LL ret=1;
    for(;tim;tim/=2,x=x*x%mo)
    if (tim&1)ret=ret*x%mo;
    return ret;
}

LL add(LL x,LL y){return x+y>=mo?x+y-mo:x+y;}
LL dec(LL x,LL y){return x<y?x-y+mo:x-y;}

struct comp{
    db x,y;
    comp(const db x_=0,const db y_=0){x=x_;y=y_;}
}mi[MAXN],A[MAXN],B[MAXN],C[MAXN],D[MAXN];
comp operator *(comp a,comp b){return comp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
comp operator +(comp a,comp b){return comp(a.x+b.x,a.y+b.y);}
comp operator -(comp a,comp b){return comp(a.x-b.x,a.y-b.y);}
comp conj(comp a){return comp(a.x,-a.y);}
int N;

LL js[MAXN],inv[MAXN];

LL calc(int n,int m){return js[n]*inv[m]%mo*inv[n-m]%mo;}

void prepare(){
    fo(i,0,maxn)mi[i]=comp(cos(pi*2/maxn*i),sin(pi*2/maxn*i));
    js[0]=inv[0]=inv[1]=1;
    fo(i,1,maxn)js[i]=js[i-1]*i%mo;
    fo(i,2,maxn)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
    fo(i,2,maxn)inv[i]=inv[i]*inv[i-1]%mo;
}

void DFT(comp *a){
    for(int i=0,j=0;i<N;i++){
        if (i<j)swap(a[i],a[j]);
        int x=N>>1;
        for(;(j^x)<j;x>>=1)j^=x;
        j^=x;
    }
    for(int i=1,d=1;i<N;i<<=1,d++)
        for(int j=0;j<N;j+=(i<<1))
            for(int k=0;k<i;k++){
                comp l=a[j+k],r=a[i+j+k]*mi[(maxn>>d)*k];
                a[i+j+k]=l-r;
                a[j+k]=l+r;
            }
}

void IDFT(comp *a){
    DFT(a);
    reverse(a+1,a+N);
    fo(i,0,N-1)a[i].x/=N,a[i].y/=N;
}

LL origin[MAXN],ny[MAXN],tmp[MAXN];

void multi(LL *a,LL *b,LL *c,int n,int m){
    N=1;
    while(N<=n+m)N<<=1;
    fo(i,0,N-1)A[i]=B[i]=comp(0,0);
    fo(i,0,n)A[i]=comp(a[i]/Blk,a[i]%Blk);
    fo(i,0,m)B[i]=comp(b[i]/Blk,b[i]%Blk);
    DFT(A),DFT(B);
    
    fo(i,0,N-1){
        comp a0=A[i],a1=A[i==0?0:N-i],b0=B[i],b1=B[i==0?0:N-i];
        comp A0=(a0+conj(a1))*comp(0.5,0),A1=(a0-conj(a1))*comp(0,-0.5);
        comp B0=(b0+conj(b1))*comp(0.5,0),B1=(b0-conj(b1))*comp(0,-0.5);
        C[i]=A0*B0+A1*B0*comp(0,1),D[i]=A0*B1+A1*B1*comp(0,1);
    }
    
    IDFT(C),IDFT(D);
    
    fo(i,0,n+m){
        db cx=C[i].x,cy=C[i].y,dx=D[i].x,dy=D[i].y;
        LL v0=cx+0.3,v1=cy+0.3,v2=dx+0.3,v3=dy+0.3;
        v0=v0%mo,v1=v1%mo,v2=v2%mo,v3=v3%mo;
        v0=v0*Blk%mo*Blk%mo;v1=v1*Blk%mo;v2=v2*Blk%mo;
        c[i]=(v0+v1+v2+v3)%mo;
    }
}
long long pr(long long x, long long y)
{
    long long res = 1; 

    x = x % mod;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;

        y = y>>1; // y = y/2
        x = (x*x) % mod;  
    }
    return res;
}


long long fact[1000006];
long long invfact[1000006];
signed main(){
    long long t;
    cin >> t;
    fact[0] = 1;
    invfact[0] = 1;
    for(long long i = 1; i < 1e6; i++){
        fact[i] = (fact[i-1] * i)%mod;
        invfact[i] = pr(fact[i], mod-2);
    }
    prepare();
    while(t--){
        long long n;
        cin >> n;
        long long a[4*n], F[4*n], INV[4*n];
        memset(a, 0, sizeof(a));
        memset(INV, 0, sizeof(INV));
        for(long long i = 0; i < n; i++){
            F[i] = 0;
            cin >> a[i];
            a[i] = (a[i] * pr(2, n - i - 1))%mod;
            a[i] = (fact[i] * a[i])%mod;
            INV[i] = invfact[n-i-1];
        }
        multi(a, INV  ,F,n, n);
        // for(long long i = 0; i < 2*n; i++){
            // cout << F[i]%mod << ' ';
        // }
        // cout << '\n';
        // must do fft below
        // for(long long i = 0; i < n; i++){
        //     for(long long j = i; j < n; j++){
        //         // F[i] = (F[i] + a[j] * invfact[j-i])%mod;
        //         long long temp = a[j];
        //         temp*= fact[j];
        //         temp%=mod;
        //         temp*= invfact[j-i];
        //         temp%=mod;
        //         temp*= invfact[i];
        //         temp%=mod;
        //         // cout << temp << '\n';
        //         F[i] += temp;
        //         F[i] %= mod;
        //     }
        // }
        for(long long i = 0; i < n; i++){
            F[i + n - 1] *= invfact[i];
            F[i + n - 1] %= mod;
            cout << F[i+n-1] << ' ';
        }
        cout << '\n';
    }
}