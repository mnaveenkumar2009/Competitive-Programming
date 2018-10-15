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
#define revsort1(a) sort(a.begin(),a.end(),greater <int>())
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

ll pr(ll x, ll y)
{
    ll res = 1; 

    x = x % mod;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;

        y = y>>1; // y = y/2
        x = (x*x) % mod;  
    }
    return res;
}
int main()
{
    ll t=sc,i,j,k;
    
    while(t--){
        ll n=sc;
        vl a(n),b(n);
        f(i,n){
            a[i]=sc;
        }
        f(i,n){
            b[i]=sc;
        }
        bool we=1;

        f(i,n-2){
            if(a[i]<b[i]){
                ll dif=b[i]-a[i];
                a[i]+=dif;
                a[i+1]+=dif*2;
                a[i+2]+=dif*3;
            }
        }
        f(i,n){
            if(a[i]!=b[i])we=0;
            // cout<<a[i]<<' '<<b[i]<<'\n';
        }

        if(we){
            cout<<"TAK\n";
        }
        else{
            cout<<"NIE\n";
        }
    }
    return 0;
}