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
#define vvl vector <vector <ll> >
#define vl vector <ll>
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

int main()
{
    ll n=sc,m=sc;
    vvl a(n,vl (m));
    
    ll i,j,k;
    ll ans=0;
    f(i,n){
        f(j,m){
            a[i][j]=sc;
        }
    }
    f(i,n){
        f(j,m){
            for(ll i2=i;i2<n;i2++){
                for(ll j2=j;j2<m;j2++){
                    set <vector<ll> > ann;
                    for(ll row=i;row<=i2;row++){
                        vector <ll> x;
                        for(ll col=j;col<=j2;col++){
                            x.pb(a[row][col]);
                        }
                        ann.insert(x);
                    }
                    ans+=ann.size();
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

/*
3 3
1 2 3
1 2 3
1 2 3
*/