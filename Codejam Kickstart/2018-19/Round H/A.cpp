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
    cout<<tt<<'\n';
    f(kkk,tt){
        ll ans=0,i,j;
        ll n=sc,k=sc;
        vector <string > a;
        f(i,k){
            string s;
            cin>>s;
            a.pb(s);
        }
        // sort1(a);
        // return 0;
        vector <ll> eras;
        f(i,k){
            f(j,k){
                if(i!=j){
                    if(a[j].find(a[i])==0){
                        // cout<<i<<j<<'\n';
                        eras.pb(j);
                    }
                }
            }
        }
        // return 0;
        sort1(eras);
        for(auto it: eras){
            // cout<<it<<' ';
        }
        vector <string > b;
        f(i,k){
            if(!binary_search(eras.begin(),eras.end(),i)){
                b.pb(a[i]);
            }
        }
        // return 0;
        cout<<n<<'\n';
        cout<<b.size()<<'\n';
        f(i,b.size()){
            cout<<b[i].length()<<'\n';
        }
        // cout<<"Case #"<<kkk+1<<": "<<ans<<'\n';
        // 8-1-2
    }

    return 0;
}