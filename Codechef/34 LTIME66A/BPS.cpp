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
        ll n=sc,m=sc,i,j;
        vl a(n),tem(n),ex(n);
        vector <pair <ll,ll> > b;
        f(i,n){
            a[i]=sc;
        }
        tem=ex=a;
        f(i,m){
            ll x=sc-1,y=sc-1;
            b.pb(mp(x,y));
        }
        for(auto it:b){
            reverse(a.begin()+it.ff,a.begin()+it.ss+1);
        }
        // prin(a);
        swap(a,ex);
        ll ans=0;

        sort1(b);
        ll xxx=0;
        do{
            tem=a;                
            for(auto it:b){
                reverse(tem.begin()+it.ff,tem.begin()+it.ss+1);
            }
            xxx++;
            if(tem==ex)ans++;
        }
        while(next_permutation(b.begin(),b.end()));
        ll temm=__gcd(ans,xxx);
        ans/=temm;
        xxx/=temm;
        cout<<ans<<'/'<<xxx<<'\n';
    }

    return 0;
}