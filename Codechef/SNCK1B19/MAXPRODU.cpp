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

int main()
{
    ll tt=sc,kkk;

    f(kkk,tt){
        ll n=sc,k=sc;
        ll i,j;
        vl a(k);
        ll star=n-((k*(k-1))/2);
        ll mis=star%k;
        star/=k;
        if(star<=0){
            cout<<"-1\n";
            continue;
        }
        else{
            f(i,k){
                a[i]=star+i;
            }
            for(i=k-1;mis--;i--){
                a[i]++;
            }
            // prin(a);
            ll ans=1;
            f(i,k){
                ans*=a[i]-1;
                ans%=mod;
                ans*=a[i];
                ans%=mod;
            }
            cout<<ans<<'\n';
        }
    }

    return 0;
}