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

const ll N = 2e6+2;
ll n=N; 
ll tree[2 * N]={0};

void modify(ll p, ll value) {  // set value at position p
    for (tree[p += n] = value; p > 1; p >>= 1) tree[p>>1] = max(tree[p], tree[p^1]);
}

ll query(ll l, ll r) {  // sum on interval [l, r)
    if(r<=l)return 0;
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res = max(tree[l++],res);
        if (r&1) res = max(tree[--r],res);
    }
    return res;
}
int main(){

    vector <bool> isp(1000006,1);
    isp[1]=0;
    isp[2]=1;
    for(ll i=2;i<1000006;i++){
        if(isp[i]){
            for(ll j=2;j*i<1000006;j++){
                isp[i*j]=0;
            }
        }
    }
    // vector <ll> sum=isp;
    ll i;
    f(i,2*N){
        tree[i]=0;
    }
    // f(i,1000006){
    //     sum[i]--;
    //     // if(i<7)cout<<sum[i]<<' ';
    // }
    for(ll i=2;i<5e5+6;i++){
        ll tem=0;
        if(isp[i]){
            tem=query(0,i)+1;
            // cout<<tem<<'\n';
        }
        else{
            ll x=i;
            for (ll i2=2;i2<=sqrt(x);i2++){
                while(x%i2==0){
                    x/=i2;
                    tem^=query(i2,i2+1);
                }
                if(x==1)break;
            }
            if(x!=1){
                tem^=query(x,x+1);
            }
            // tem++;
        }
        // cout<<"i "<<i<<'\n';
        // cout<<tem<<'\n';
        modify(i,tem);
    }
    f(i,30){
        // cout<<i+0<<' '<<query(i+0,i+0+1)<<'\n';
    }
    ll t=sc;
    while(t--){
        ll nn=sc;
        ll nim=0;
        while(nn--){
            ll x=sc;
            nim^=query(x,x+1);
        }
        if(nim){
            cout<<"Alice\n";
        }
        else{
            cout<<"Bob\n";
        }
    }
    return 0;
}