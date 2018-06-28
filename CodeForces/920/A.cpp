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
    int i,t=sscan();
    while(t--){
        int n,k;
        cin>>n>>k;
        int ans=0;
        vector <bool> a(n,0);
        while(k--){
            a[sscan()-1]=1;
        }
        while(1){
            ans++;
               
            bool we=1;
            f(i,n){
                if(!a[i])we=0;
            }
            if(we)break;
            //f(i,n)cout<<a[i];
            f(i,n){
                if(i){
                    if(a[i-1]&&!a[i])a[i]=1,i++;
                }
                if(i<n-1){
                    if(a[i+1]&&!a[i])a[i]=1;
                }
            }
        }
        cout<<ans<<endl;
    }
	return 0;
} 