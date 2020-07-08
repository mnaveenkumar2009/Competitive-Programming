#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define f(i,n) for(i=0;i<n;i++)
inline ll uscan()
{
    ll n=0,c=gc();
    bool check=0;
    if(c=='-')check=1;
    while(c<'0'||c>'9')
    {
        c=gc();
        if(c=='-')check=1;
    }
    while(c<='9'&&c>='0'){
        n=n*10+c-'0';
        c=gc();
    }
    return n+(-2*check*n);
}


int main() {
    ll t=1;
    ll kkk=0;
    ios_base::sync_with_stdio(0);
    f(kkk,t){
        ll n=uscan(),i,j;
        bool we=0,we2=0;
        vector <ll> a(n);
        f(i,n){
            a[i]=uscan();
            if(a[i]>=0)
                we=1;
            if(a[i]<=0)
                we2=1;
        }
        if(n==1){
            cout<<a[0];
            return 0;
        }
        if(n==2){
            cout<<abs(a[0]-a[1]);
            return 0;
        }
        ll sum=0;
        f(i,n){
            sum+=abs(a[i]);
        }
        if(we&&we2){            
            cout<<sum;
            return 0;
        }
        f(i,n){
            a[i]=abs(a[i]);
        }
        ll mini=INT_MAX;
        f(i,n){
            mini=min(mini,a[i]);
        }
        cout<<sum-2*mini;
    }
    return 0;
}