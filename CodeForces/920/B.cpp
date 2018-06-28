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
    int t=sscan();
    while(t--){
        int n=sscan();
        int i,j;
        ll cur=0;
        vector <vector <ll> > a(5009);
        vector <ll> b(n),cc(n);
        f(i,n){
            a[(cc[i]=sscan())-1].pb(i);
            b[i]=sscan();
            //cout<<cc[i]<<" ";
        }//cout<<endl;
        vector <int> p;
        f(i,5009){
            f(j,a[i].size()){
                p.pb(a[i][j]);
            }
        }
       // f(i,n)cout<<p[i]<<" ";cout<<endl;
        vector <int> ans(n);
        f(i,n){
            //cout<<cur<<" "<<b[p[i]]<<endl;
            cur=max(cur,cc[p[i]]-1);
            if(cur+1>b[p[i]])
            {ans[p[i]]=0;}
            else
            {ans[p[i]]=++cur;
            //cout<<p[i]<<endl;
            }
        }
        f(i,n)printf("%d ",ans[i]);
        cout<<endl;
    }
	return 0;
} 