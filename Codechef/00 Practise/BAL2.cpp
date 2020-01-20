#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef long double db;

#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define endl "\n"
#define sz(x) ((ll)((x).size()))
const ll N=1e5+5,inf=1e18,mod=1e9+7;
namespace FFT{
	const db PI = acos((db)-1);
	template < class T> class comp{
		public: T r,i; comp(T a = (T)0 , T b = (T)0 ) : r(a), i(b){}
		comp conj() { return comp(this->r, -(this->i)); }
		comp operator=(const comp& a){ this->r = a.r, this->i=a.i; return * this; }
		comp operator+(const comp& b){ return comp(r+b.r, i+b.i) ;}
		comp operator-(const comp& b){ return comp(r-b.r, i-b.i) ;}
		comp operator*(const T& num){ return comp(r*num, i*num) ;}
		comp operator/(const T& num){ return comp(r/num, i/num) ;}
		comp operator*(const comp& b){return comp(r*b.r-i*b.i,i*b.r+r*b.i);}
		comp operator/(const comp& b){return ((*this)*comp(b.r,-b.i))/(b.x*b.x+b.y*b.y);}
	};

	#define cd comp<double>
	vector<cd> w ; vll rev;
	void revb(ll nl)
	{
		static ll l = -1;
		if(nl==l) return ;
		ll t,j,k=0;
		l = nl;
		rev.resize(l+1);
		while((1<<k)<nl)++k;
		lp(i,1,l+1)
		{
			j=rev[i-1];
			t=k-1;
			while(t>=0 && ((j>>t)&1)) 
			{
				j^=(1<<t),--t;
			}
			if(t>=0) j^=(1<<t),--t;
			rev[i]=j;
		}
	}
	void fft(vector<cd> & poly, ll inv=false)
	{
		ll len,l;
		revb(sz(poly));
		lp(i,0,sz(poly))
		{
			if(rev[i]>i)swap(poly[i],poly[rev[i]]);
		}
		cd u,v;
		if(sz(w)<sz(poly)) w.resize(sz(poly));
		for(len=2,l=1;len<=sz(poly);len+=len,l+=l)
		{
			if(w[l].r==0 && w[l].i==0)
			{
				db ang=PI/l; 
				cd ww(cos(ang),sin(ang));
				if(l>1)
				{
					lp(j,0,l)
					{
						w[l+j]=(j&1) ?  w[(l+j)>>1]*ww : w[(l+j)>>1];
					}
				}
				else
				{
					w[l]=cd(1.0,0.0);
				}
			}
			for(ll i=0 ; i < sz(poly); i+=len)
			{
				lp(j,0,l)
				{
					u=poly[i+j],v=poly[i+j+l]*(inv ? w[l+j].conj() : w[l+j]);
					poly[i+j] = u + v , poly[i+j+l] = u-v;
				}
			}
		}
		if(inv)
		{
			for(auto &x : poly) x= x/sz(poly) ;
		}
	}
	vll multiply( vll &a , vll &b)
	{
		ll bi=1,sz1=sz(a)+sz(b), rsz;
		while((1<<bi)<sz1) ++bi; 
		rsz=(1<<bi);
		vector<cd> poly(rsz);
		lp(i,0,sz(a))
		{
			poly[i].r=a[i];
		}
		lp(i,0,sz(b))
		{
			poly[i].i=b[i];
		}
		fft(poly);
		cd p , qtmp, q ;
		poly[0] = poly[0].r * poly[0].i;
		lp(i,1,(rsz>>1)+1)
		{
			p=poly[i]+poly[rsz-i].conj(), qtmp=poly[rsz-i]-poly[i].conj();
			q.r=qtmp.i,q.i=qtmp.r ;
			poly[i]=(p*q)*0.25;
			if(i) poly[rsz-i]=poly[i].conj();
		}
		fft(poly,true);
		vll ans(sz1-1);
		lp(i,0,sz(ans))
		{
			ans[i]=(ll)(poly[i].r+0.5);
		}
		return ans;
	}
	ll add(ll x,ll y)
	{
		ll ret=x+y;
		return ret<0 ? ret+mod : ret>=mod? ret-mod : ret;
	}
	vll multmod(vll a, vll b)
	{
		vll C(sz(a), 0),D(sz(b), 0);
		lp(i,0,sz(a))
		{
			C[i]=a[i]&0xFFFF;
			a[i]=a[i]>>16;
		}
		lp(i,0,sz(b))
		{
			D[i]=b[i]&0xFFFF;
			b[i]=b[i]>>16;
		}
		vll z1=multiply(C,D),z2=multiply(a,b);
		lp(i,0,sz(a))
		{
			a[i]=add(a[i],C[i]);
		}
		lp(i,0,sz(b))
		{
			b[i]=add(b[i],D[i]);
		}
		vll z3= multiply(a,b);
		lp(i,0,sz(z3))
		{
			ll x=z1[i]+z2[i];
			x%=mod;
			z3[i]=(z3[i]-x+mod)%mod;
			z2[i]%=mod;
			z3[i]=((ll)z3[i]<<16)%mod;
			z2[i]=((ll)z2[i]<<32)%mod;
		}
		lp(i,0,sz(z3))
		{
			z3[i]+=z1[i];
			z3[i]+=z2[i];
			z3[i]%=mod;
		}
		return z3;
	}
}
ll expo(ll a, ll b, ll mod) {
    ll ans = 1;
    while(b!=0 ) 
    {
        if((b&1) == 1) 
            ans = (ans*a)%mod ;
        a= (a*a)%mod;
       	b>>= 1;
    }
    return ans%mod;
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	ll n,k;
	cin >> n >> k;
	ll ans=0;
	vll col[n];
	ll pk[n+1];
	lp(i,0,n)
	{
		ll c;
		cin >> c;
		c--;
		col[c].pb(i);
	}
	pk[0]=1;
	lp(i,1,n+1)
	{
		pk[i]=expo(i+1,k,mod);
		// cout<<pk[i]<<endl;
	}
	lp(i,0,n)
	{
		// cerr<<i<<endl;
		if(sz(col[i])==0)
		{
			continue;
		}
		vll a,b;
		a.pb(col[i][0]+1);
		lp(j,0,sz(col[i])-1)
		{
			a.pb(col[i][j+1]-col[i][j]);
		}
		a.pb(n-col[i][sz(col[i])-1]);
		ll nn=sz(a);
		b=a;
		reverse(all(b));
		vll ret=FFT::multmod(a,b);

		ll cur=0;
		rlp(j,nn-2,0)
		{
			ans+=ret[j]*pk[cur++];
			ans%=mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}