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
#define gc getchar
#define pc putchar
inline unsigned long long uscan()
{
    unsigned long long n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}
 
inline long int lscan()                 
{
    long int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}
 
 
inline  int sscan()                     
{register  int n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0')
    {
n=n*10+c-'0';
c=gc();
    }
return n;
}

int main()
{	
	int n=sscan(),m=sscan();
    map <string,string> ans;
    int i;
    f(i,n){
        string a,b;
        cin>>a>>b;
        ans[b]=a;
    }
    while(m--){
        string a,b,c;
        cin>>a>>b;
        f(i,b.length()){
            if(i<b.length()-1)
            c.pb(b[i]);
        }
        cout<<a<<" "<<b<<" "<<'#'<<ans[c]<<endl;
    }
	return 0;
} 