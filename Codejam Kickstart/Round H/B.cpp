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
    // cout<<tt<<'\n';
    f(kkk,tt){
        ll ans=0,i,j;
        ll n=sc;
        vector <char> s(n);
        f(i,n){
            cin>>s[i];
        }
        vl sum(n,0);
        f(i,n){
            sum[i]=s[i]-'0';
        }
        f(i,n-1){
            sum[i+1]+=sum[i];
        }
        f(i,n){
            if((i-((n+1)/2))>=0)
                ans=max(sum[i]-sum[i-((n+1)/2)],ans);
            if((i-((n+1)/2))==-1){
                ans=max(sum[i],ans);
            }
        }
        cout<<"Case #"<<kkk+1<<": "<<ans<<'\n';
    }

    return 0;
}