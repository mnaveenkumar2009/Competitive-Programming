// fft template : https://www.codechef.com/viewsolution/18698974

#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define double long double
inline ll uscan()
{
    ll n=0,c=gc();
    bool check=0;
    if(c=='-')check=1;
    while(c<'0'||c>'9')
    {
        c=gc();
        if(c=='-')check=1;
    }
    while(c<='9'&&c>='0'){
        n=n*10+c-'0';
        c=gc();
    }
    return n+(-2*check*n);
}
#define sc uscan()
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

const int L = 50005;

void getny(int n){
	if (n==1){ny[0]=quickmi(origin[0],mo-2);return;}
	int l;
	getny(l=n/2+(n&1));
	multi(ny,ny,tmp,l-1,l-1);
	multi(tmp,origin,tmp,2*l-2,n-1);
	fo(i,0,n-1)ny[i]=(ny[i]*2+mo-tmp[i])%mo;
}

//Bernouli

LL b[MAXN];

void Bernouli(){
	fo(i,0,L)origin[i]=dec(0,inv[i+1]);
	getny(L+1);
	fo(i,0,L)b[i]=ny[i];
	fo(i,0,L)origin[i]=ny[i]=0;
}


#define MAXX MAXN

ll fac[MAXX+5],ifac[MAXX+5];
ll ncr(ll n,ll r){
    return (((fac[n]*ifac[n-r])%mod)*ifac[r])%mod;
}
int main()
{
    prepare();
    ll i,j,k;
    fac[0]=ifac[0]=1;
    f(i,MAXX+3){
        fac[i+1]=((i+1)*fac[i])%mod;
        ifac[i+1]=fpow(fac[i+1],mod-2);
    }
    Bernouli();
    f(i,MAXN)b[i]=(mod-b[i])%mod;
    b[1]++;
    // f(i,50)cout<<b[i]<<' ';cout<<'\n';
    ll t=sc;
    while(t--){
        ll n=sc,m=sc,k=sc;
        ll a[m+n+5]={0},coef[m+n+5]={0},newb[m+n+5]={0},c[2*(m+n+5) + 5]={0};
        f(i,m+n+5){
            
            if(i)
            a[i-1]=(fpow(k,i)*ifac[i])%mod;
            newb[i]=b[i];
        }
        
        // vector <ll> c=multiply(a,newb);
        multi(a,newb,c,n+m,n+m);
        f(i,m+n+5){
            c[i]*=fac[i];
            c[i]%=mod;
        }
        // f(i,m+n)cout<<c[i]<<' ';cout<<'\n';
        // f(i,m+n)cout<<a[i]<<' ';cout<<'\n';
        // f(i,m+n)cout<<b[i]<<' ';cout<<'\n';
        coef[m+n]=1;
        f(i,m+1){
            if(i&1){
                coef[n+m-i]+=ncr(m,i);
            }
            else{
                coef[n+m-i]-=ncr(m,i);
            }
        }
        f(i,n+1){
            if(i&1){
                coef[m+n-i]+=ncr(n,i);
            }
            else{
                coef[m+n-i]-=ncr(n,i);
            }
        }
        f(i,m+n+1){
            if(i&1){
                coef[m+n-i]-=ncr(m+n,i);
            }
            else{
                coef[m+n-i]+=ncr(m+n,i);
            }
        }
        ll ans=0;
        f(i,m+n+5){
            // cout<<coef[i]<<'\n';
            ans+=(coef[i]*c[i])%mod;
            ans%=mod;
        }
        cout<<(ans+mod)%mod<<'\n';
    }
    return 0;
}
