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

vector <ll> divi[200004];
vector <ll> ddiv[200004];

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
void seive2(){
    ll i;
    f(i,100005){
        ll a=i+1;
        for(ll j=1;j<=sqrt(a);j++){
            if(a%j==0)
                {
                   ddiv[a].pb(j);
                   if(j!=a/j){
                       ddiv[a].pb(a/j);
                   }
                }
        }
    }
}
int main()
{
    ll tt=sc,kkk;
    seive();
    seive2();
    f(kkk,tt){
        ll n=sc,maxi=0,i,j;
        vl a(n);
        vl b(100005,0),ans(100005,0);
        f(i,n){
            a[i]=sc;
            // for(ll j=1;j<=sqrt(a[i]);j++){
            //     if(a[i]%j==0)
            //         {
            //             b[j]++;
            //             b[a[i]/j]++;
            //         }
            // }
            // // cout<<b[2]<<'\n';
            // if((ll)sqrt(a[i])*sqrt(a[i])==a[i]){
            //     b[sqrt(a[i])]--;
            // }
            for(auto it: ddiv[a[i]]){
                b[it]++;
            }
        }
        // f(i,10)cout<<b[i]<<' ';pc('\n');
        f(i,100005){
            ans[i]=b[i]*divi[i].size();
        }
        f(i,100005){
            maxi=max(ans[i],maxi);
        }
        cout<<maxi<<'\n';
    }

    return 0;
}