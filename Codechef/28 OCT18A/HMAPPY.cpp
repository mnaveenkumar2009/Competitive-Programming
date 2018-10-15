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
#define vl vector <ll> 
#define vvl vector <vector <ll> >
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
void prin(vector <vector <ll> > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j]<<' ';
        pc('\n');
    }
    pc('\n');
}
void prin(vector <vector <pair <ll,ll> > > a){
    ll i,j;
    f(i,a.size()){
        f(j,a[i].size())
            cout<<a[i][j].ss<<' ';
        pc('\n');
    }
    pc('\n');
}
ll ds(ll n){
    ll ans=0;
    while(n!=0){
        ans+=n%10;
        n/=10;
    }
    return ans;
}
ll t=-100;
int main()
{

    ll n=sc,m=sc,i,j,k;
    vl a(n),b(n);
    f(i,n)a[i]=sc;
    f(i,n)b[i]=sc;
    ll low=0,high=1e18+5;
    while(low!=high){
        ll mid=(low+high)/2;
        // if(low==high-1)mid++;
        ll bal=0;
        f(i,n){
            bal+=max(a[i]-(mid/b[i]),0LL);
        }
        if(bal<=m){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    cout<<low<<'\n';
    
    return 0;
}