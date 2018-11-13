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
#define sort1(a) sort(a.begin(),a.end())
#define sort2(a,n) sort(a,a+n)

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

void prin(vector <ll> a){
    ll i;
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin(ll a[],ll n){
    ll i;
    f(i,n){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin(vector <vector <ll> > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j]<<' ';
        pc('\n');
    }
    pc('\n');
}
void prin(vector < pair<ll,ll> > a){
    ll i,j;
    f(i,a.size()){
        cout<<a[i].ff<<' '<<a[i].ss<<'\n';
    }
    pc('\n');
}
#define vl vector <ll> 
#define vvl vector <vector <ll> >
ll pr(ll x, ll y)
{
    ll res = 1; 

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
vvl dp(1009,vl(1009,0));
void pre(){
	ll i,j;
    dp[0][0]=dp[1][0]=dp[1][1]=1;
	for(i=1;i<1001;i++)
	    dp[i][0]=1;
	for(i=1;i<1001;i++){
	    for(j=1;j<i+1;j++){
	        dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;   
        }
	}
}
int main()
{
    pre();
    // cout<<dp[100][101];
	ll t=sc;
	while(t--){
		ll n=sc,i,j,k;
        vl a(n);
		f(i,n)a[i]=sc;
		sort1(a);
		ll ans=pr(2,n-1)%mod;
		f(i,n)
			for(j=i+1;j<n;j++){
                if(a[i]!=a[j])	break;
				ll k=min(i,n-1-j);
				ll tem=(dp[i+n-1-j][k])%mod;
				ans=(ans+tem)%mod;
			}
		
	    cout<<(ans+mod)%mod<<'\n';
	}
}