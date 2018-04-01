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
 
inline  ll sscan()                     
{
ll n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0')
    {
n=n*10+c-'0';
c=gc();
    }
return n;
}

int main(){
    int t=sscan();
    while(t--){
        int n=sscan();
        vector <int> a(n);
        int i;
        f(i,n)a[i]=sscan();
        sort(a.begin(),a.end());
        int count=0;
        f(i,n-1){
            if(a[i+1]==a[i])count++;
        }
        cout<<count<<endl;
    }
    return 0;
}