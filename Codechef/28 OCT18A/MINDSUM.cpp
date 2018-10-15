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
ll ds(ll n){
    ll ans=0;
    while(n!=0){
        ans+=n%10;
        n/=10;
    }
    return ans;
}
ll t=-100;
int main()
{
    t=sc;
    while(t--){
        ll n=sc,i,j;
        ll d=sc;
        vector <pair <ll,ll> > ans;
        ans.pb(mp(n,0));
        f(i,100){
            ll nnn=n;
            nnn+=d*i;
            ll cou=i;
            while(nnn>9){
                nnn=ds(nnn);
                cou++;
            }
            ans.pb(mp(nnn,cou));
        }
        sort(ans.begin(),ans.end());
        ll mini=ans[0].ff;
        ll steps=ans[0].ss;
        while(steps--){
            bool we=0;
            for(ll mask=0;mask<(1<<steps);mask++){
                ll nnn=n;
                for(ll j=0;j<steps;j++){
                    if((1LL<<j)&mask){
                        nnn+=d;
                    }
                    else{
                        nnn=ds(nnn);
                    }
                }
                if(nnn==mini)
                {
                    we=1;break;
                }
            }
            if(!we)break;
        }
        cout<<mini<<' '<<steps+1<<'\n';
    }
    return 0;
}