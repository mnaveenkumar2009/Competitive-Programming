#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define sd(n) scanf("%d",&n)
#define sc(n) scanf("%c",&n)
#define slld(n) scanf("%lld",&n)
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
inline ll uscan()
{
    ll n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}
int main() {
    int t=uscan();
    while(t--){
        ll x=uscan(),y=uscan(),i,j;
        ll a[x],b[y],c[x+y];
        f(i,x)a[x-i-1]=uscan();
        f(i,y)b[y-i-1]=uscan();
        ll temp=x+y;
        f(i,temp){
            // cout<<x<<' '<<y<<'\n';
            if(x&&y){
                if(a[x-1]<b[y-1]){
                    x--;
                    c[i]=a[x];
                }
                else{
                    y--;
                    c[i]=b[y];
                }
            }
            else{
                if(x)c[i]=a[--x];
                else
                c[i]=b[--y];
            }
            // cout<<c[i]<<'\n';
        }
        f(i,temp)cout<<c[i]<<' ';cout<<'\n';
    }
	return 0;
}