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
vector <ll> divi[200004];

void seive(){
    ll i,j,k;

    for(i=2;i<200006;i++){
        if(divi[i].size()==0){
            divi[i].pb(i);
            for(j=2;j*i<200004;j++){
                divi[j*i].pb(i);
            }
        }
    }
}
int main()
{
    seive();
    ll n=sc,i,j,k;
    vl div(1000007,0);
    vl xxx(1000007,1);
    for(i=2;i<1000007;i++){
        if(xxx[i]==1){
            for(j=2;j*i<1000007;j++){
                xxx[i*j]++;
            }
        }
    }
    xxx[1]=0;
    f(i,1e6){
        if(xxx[i]>1)xxx[i]--;
    }
    f(i,n){
        ll x=sc;
        for(j=1;j<=sqrt(x);j++){
            if(x%j==0){
                // cout<<x<<' '<<j<<'\n';
                div[j]++;
                div[x/j]++;
                if(j==(x/j))div[j]--;
            }
        }
    }
    // f(i,1000){
    //     if(div[i])
    //     cout<<i<<' '<<div[i]<<'\n';
    // }
    // cout<<'\n';
    ll ans=0;
    f(i,200003){
        ll xx=1;
        for(auto it:divi[i]){
            xx*=it;
        }
        if(xx!=i)continue;
        if(xxx[i]&1)
            ans=(ans-pr(2,div[i])+1)%mod;
        else{
            ans=(ans+pr(2,div[i])-1)%mod;
        }
        if(div[i]){
            // cout<<i<<' '<<div[i]<<' '<<ans<<'\n';
        }
    }
    
    ans+=mod;
    ans%=mod;
    cout<<ans;
    return 0;
}