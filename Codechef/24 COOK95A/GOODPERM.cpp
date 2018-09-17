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
#define NIL -1
inline ll uscan()
{
    ll n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c <= '9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}
 
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
 
 
int main()
{
    ll t=uscan(),kkk;
    
    f(kkk,t){
        ll n=uscan(),k=uscan();
        ll a[n];
        int i;
        f(i,n)a[i]=uscan();
        vector <ll> b(n);
        f(i,n)b[i]=i+1;
        ll c=0;
        do {
            bool we=1;
            f(i,n){
                if(b[i]!=a[i]&&a[i])we=0;
                //cout<<b[i]<<' '<<a[i]<<"v ";
            }//pc('\n');
            ll co=0;
            f(i,n){
                if(b[i]>b[i-1])co++;
            }
            if(co!=k)we=0;
            c+=we;
        } while ( std::next_permutation(b.begin(),b.end()) );
        cout<<c<<'\n';
    }
	return 0;
}