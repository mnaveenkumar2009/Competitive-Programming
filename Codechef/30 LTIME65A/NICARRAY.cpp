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
unordered_map <string,ll> xxx;
string has(vector <ll> a){
    string ret;
    for(auto it:a){
        ret.pb(it);
    }
    return ret;
}
ll n,s;
ll f2(vector <ll> a){
    string ss = has(a);
    vector <ll> b=a;
    sort1(a);
    if(b!=a)return a;
    if(xxx[ss]){
        return xxx[ss];
    }
    ll ret=0,sum=0,minus1=0,i,j;
    f(i,n){
        if(a[i]!=-1){
            sum+=a[i];
        }
        else{
            minus1++;
        }
    }
    if(minus1==0&&sum!=s)
        return 0;
    if(minus1==0){
        // prin(a);
        ll rett=0;
        f(i,n){
            f(j,i){
                rett+=__gcd(a[i],a[j]);
            }
        }
        xxx[ss]=rett;
        return rett;
    }
    // ll ret=0;
    f(i,n){
        if(a[i]==-1){
            f(j,(s-(sum+minus1-1))){
                vector <ll> b=a;
                b[i]=j+1;
                ret=(ret+f2(b))%mod;
            }
            break;
        }
    }
    xxx[ss]=ret;
    return ret;
}
int main()
{
    ll tt=sc,kkk;

    f(kkk,tt){
        n=sc,s=sc;
        ll i,j,k;
        vl a(n);
        f(i,n){
            a[i]=sc;
        }
        sort1(a);
        cout<<f2(a)<<'\n';
    }

    return 0;
}