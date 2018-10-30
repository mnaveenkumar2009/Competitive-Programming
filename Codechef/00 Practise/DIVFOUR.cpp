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
    string s;
    cin>>s;
    ll n=s.length();
    vector <ll> a(n);
    ll i,j,k;
    f(i,n){
        a[i]=s[i]-'0';
    }
    vector <ll> sum1(n,0),sum2(n,0);
    f(i,n){
        if(a[i]%2==0){
            if(a[i]%4==0){
                sum2[i]=1;
            }
            else{
                sum1[i]=1;
            }
        }
    }
    f(i,n-1){
        sum1[i+1]+=sum1[i];
        sum2[i+1]+=sum2[i];
    }
    ll ans=0;
    // prin(sum1);
    // prin(sum2);
    f(i,n){
        if(a[i]&1){
            // odd
            ans=(ans+(sum1[n-1]-sum1[i])*pr(2,i))%mod;
        }
        else{
            ans=(ans+(sum2[n-1]-sum2[i])*pr(2,i))%mod;
        }
        // cout<<ans<<' ';    
    }
    ans+=sum2[n-1];
    cout<<ans;
    return 0;
}