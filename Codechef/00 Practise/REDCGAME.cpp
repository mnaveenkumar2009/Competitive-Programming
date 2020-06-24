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

void prin(vector <ll> a){
    ll i;
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin(ll a[],ll n){
    ll i;
    f(i,n){
        cout<<a[i]<<' ';
    }pc('\n');
}
void prin(vector <vector <ll> > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j]<<' ';
        pc('\n');
    }
    pc('\n');
}
void prin(vector < pair<ll,ll> > a){
    ll i,j;
    f(i,a.size()){
        cout<<a[i].ff<<' '<<a[i].ss<<'\n';
    }
    pc('\n');
}
#define vl vector <ll> 
#define vvl vector <vector <ll> >
#define vpl vector <pair <ll,ll> >


int main(){
    ll t=sc;
    while(t--){
        ll n=sc,K=sc;
        ll i,j,k=-100;
        vector <ll> a;        
        f(i,n){
            a.pb(sc);
        }
        if(n==1){
            cout<<a[0]<<'\n';
            continue;
        }
        sort1(a);
        ll sum=0,ans=0;
        f(i,n-2){
            if(a[i]>K){
                sum+=a[i]-K;
            }
        }
        f(i,n-2){
            ans+=min(a[i],K);
        }
        
        if(a[n-2]-sum>=K){
            a[n-2]-=sum;
            a[n-1]-=a[n-2]-K;
            a[n-2]=K;
            ans+=a[n-2]+a[n-1];
        }
        else{
            if(a[n-2]>K){
                sum+=a[n-2]-K;
            }
            // cout<<ans<<'\n';
            ans+=a[n-1]-sum%2;
            // cout<<ans<<'\n';
            ans+=min(a[n-2],K);
        }
        cout<<ans<<'\n';
    }
}