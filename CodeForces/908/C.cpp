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
#define ld long double
int main()
{
	int n;
	ld r;
	cin>>n>>r;
	vector <ld> a(n);
	int i,j;
	f(i,n){
		a[i]=sscan();
	//	cout<<a[i]<<endl;
	}
	vector <ld> ans(n,r);
	
	f(i,n){
		f(j,i){
			if(abs(a[j]-a[i])<=2*r){
				ld temp1=2*r,temp2=abs(a[j]-a[i]);
				temp1*=temp1;
				temp2*=temp2;
				ld temp=temp1-temp2;
				temp=sqrt(temp);
				ans[i]=max(ans[i],temp+ans[j]);	
			}			
		}
	}
	f(i,n){
		printf("%0.8Lf ",ans[i]);
	}
	
	return 0;
}