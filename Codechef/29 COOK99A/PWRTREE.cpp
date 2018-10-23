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

ll tt,kkk;
ll xxx=0;
bool adj[256][256];

void f2(ll node,ll l){
    ll i;
    f(i,l){
        adj[node][++xxx]=1;
        adj[xxx][node]=1;
        f2(xxx,l-i-1);
    }
}
int main()
{
    tt=sc,kkk;
    
    f(kkk,tt){
        xxx=0;
        ll n=sc;
        vector <pair <ll,ll> > a((n*(n-1))/2);
        ll l=log2(n);
        ll i,j,k;
        f(i,256){
            f(j,256){
                adj[i][j]=0;
            }
        }
        f(i,(n*(n-1))/2){
            a[i].ff=sc-1;
            a[i].ss=sc-1;
        }
        if((1LL<<l)!=n){
            cout<<"-1\n";
            continue;
        }
        f2(0,l);
        f(i,n){
            cout<<i<<'y'<<'\n';
            f(j,n){
                if(adj[i][j]){
                    cout<<j<<' ';
                }
            }
            cout<<'\n';
        }
        pc('\n');
        ll annn=0;
        f(i,(n*(n-1))/2){
            if(!adj[a[i].ff][a[i].ss]){
                annn++;
                // cout<<i+1<<' ';
            }
        }
        cout<<annn<<'\n';
        f(i,(n*(n-1))/2){
            if(!adj[a[i].ff][a[i].ss]){
                // annn++;
                cout<<i+1<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}