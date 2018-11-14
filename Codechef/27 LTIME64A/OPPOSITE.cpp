#include <bits/stdc++.h>
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define sort1(a) sort(a.begin(),a.end())
#define sort2(a,n) sort(a,a+n)

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
#define sc uscan()


int main()
{
    // ios::sync_with_stdio(0);
    ll t=sc,iiii;
    f(iiii,t){
        ll i,j,k;
        ll n=sc;
        ll a[n];
        // bool we=1;
        vector <ll> mi;
        f(i,n){
            a[i]=sc;
            // if(a[i]==-1)mi.pb(i);
        }
        if(n%2){cout<<"NO\n";continue;}
        // ll sum
        // ll m=mi.size();
        // ll sum=0;
        // f(i,m){
        //     if(abs(mi[i]-mi[(i+1)%m])>n/2){
        //         // ll l=min(mi[i],mi[(i+1)%m]);                
        //         // for(i=l;i<l+n/2;i++){
        //         //     sum+=a[i];    
        //         // }
        //         // sum*=2;
        //         // for(;i<n;i++){
        //         //     a[i]
        //         // }
        //         mi.erase(mi.begin(),mi.end());
        //         break;
        //     }
        // }
        // if(mi.size()){
        //     f(i,m){
        //         a[mi[mi.size()-1]]=1;
        //         ll t2=abs(mi[mi.size()-2]-mi[0]);
        //         mi.erase(mi.begin()+mi.size()-1);
        //         if(t2>n/2){
        //             break;
        //         }
        //     }
        // }
        bool we=1;
        //     
        f(i,n){
            if(a[i]==-1){
                a[i]=a[(i+n/2)%n];
            }
            if(a[(i+n/2)%n]==-1){
                a[(i+n/2)%n]=a[i];
            }
            if(a[i]!=a[(i+n/2)%n])we=0;
        }
        f(i,n){
            if(a[i]==-1)a[i]=1;
        }
        // f(i,n)cout<<a[i]<<' ';cout<<'\n';    
        if(!we){cout<<"NO\n";continue;}
        cout<<"YES\n";
        f(i,n)cout<<a[i]<<' ';
        cout<<'\n';
    }
    return 0;
}