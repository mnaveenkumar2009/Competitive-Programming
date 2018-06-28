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
    int i,n=sscan();
    int a[n];
    f(i,n)a[i]=sscan();
    int l=0,r=0;
    vector <pair<int,int> > b;
    //getchar();
    f(i,n-1){
        char c=getchar();
        //cout<<c<<endl;
        if(c=='0'){
            if(l!=i){
                b.pb(mp(l,i));
            }
            //cout<<l<<r<<endl;
            l=i+1;
        } 
    }
    if(l!=n-1){
         b.pb(mp(l,n-1));
    }
    f(i,b.size()){
        //cout<<b[i].ff<<b[i].ss<<endl;
        sort(a+b[i].ff,a+b[i].ss+1);
    }
    bool we=1;
    f(i,n-1)if(a[i]>a[i+1])we=0;
    if(!we)
        cout<<"NO\n";
    else
        cout<<"YES\n";
	return 0;
} 

