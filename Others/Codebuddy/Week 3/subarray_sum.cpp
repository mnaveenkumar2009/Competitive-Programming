/*
Given an array, find the subarray (containing at least k numbers) which has the largest sum.

Examples:

Input  : arr[] = {-4, -2, 1, -3} 

         k = 2

Output : -1

The sub array is {-2, 1}

Input  : arr[] = {1, 1, 1, 1, 1, 1} 

         k = 2

Output : 6 

The sub array is {1, 1, 1, 1, 1, 1}
*/

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
int main()
{
    int t=uscan();
    while(t--){
        ll n=uscan(),i,j;
        ll a[n];
        f(i,n)cin>>a[i];
        ll k=uscan();
        ll maxi[n];
        maxi[0]=a[0];
        f(i,n-1){
            maxi[i+1]=max(maxi[i]+a[i+1],a[i+1]);
        }
        //f(i,n)cout<<maxi[i]<<' ';cout<<'\n';
        ll sum=0;
        f(i,k)sum+=a[i];
        ll ans=sum;
        //cout<<sum<<'\n';
        f(i,n-k){
            sum=sum-a[i]+a[i+k];
            ans=max(ans,max(sum,sum+maxi[i]));
            //cout<<ans<<' '<<sum<<'\n';
        }
        cout<<ans<<'\n';
    }
	return 0;
}