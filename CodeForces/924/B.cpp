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

int main(){
    ll n=uscan(),m=uscan();
    vector <ll> a(n);
    int i;
    f(i,n)a[i]=uscan();
    ld maxi=-1;
    f(i,n-2){
        vector <ll> ::iterator jj=lower_bound(a.begin(),a.end(),a[i]+m);
        if(*jj-a[i]>m)jj--;
        else
        if(*jj==0)jj--;
        if(jj-a.begin()==i+1)continue;
        ld temp1=*jj-a[i];
        ld temp2=*jj-a[i+1];
        //cout<<temp1<<" "<<temp2<<endl;
        maxi=max((temp2/temp1),maxi);
    }
    if(maxi==-1){
        printf("-1");
    }
    else
    {
        printf("%0.15Lf",maxi);
    }
    return 0;
}