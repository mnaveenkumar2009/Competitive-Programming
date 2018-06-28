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
	vector <int> fibo;
    int i=1;
    fibo.pb(i);fibo.pb(i);
    while(i<30){
        fibo.pb(fibo[fibo.size()-1]+fibo[fibo.size()-2]);
        i++;
    }
    //cout<<fibo[fibo.size()-1]<<endl;;
    int n=sscan();
    char ans[n];
    f(i,n){
        if(binary_search(fibo.begin(),fibo.end(),i+1))ans[i]='O';
        else
            ans[i]='o';
    }
    f(i,n)putchar(ans[i]);
	return 0;
} 