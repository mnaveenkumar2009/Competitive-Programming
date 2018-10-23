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
#include <bits/stdc++.h>
#define ll long long
const ll N = 1e5+6;
ll n; 
ll t[2 * N];
unordered_map <ll,ll> pos;
void build() {  // build the tree
    // cout<<"build";
    for (ll i = n - 1; i > 0; --i) t[i] = max(t[i<<1] , t[i<<1|1]);
}

ll query(ll l, ll r) {  // swin on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res =max(res,t[l++]);
      if (r&1) res = max(t[--r],res);
    }
    return res;
}

ll f2(ll l, ll r){
    ll posi=query(l,r+1);
    posi=pos[posi];
    // cout<<l<<' '<<r<<' '<<posi<<'\n';
    if(posi==l||posi==r)return 1;

    return 1+min(f2(l,posi-1),f2(posi+1,r));
}
int main()
{
    ll tt=sc,kkk;
    string win[2]={"Dee","Dum"};
    f(kkk,tt){
        int n=sc,st=1,ct[2]={0,0};
        string s;
        cin>>s;
        if(s=="Dee")
            st=0;
        vector <string> a;
        ll i;
        f(i,n) {
            cin>>s;
            reverse(s.begin(), s.end());
            a.pb(s);
        }
        bool ans=st;
        bool we=1;
        while(we){
            we=0;
            ll i;
            f(i,n){
                if(a[i].length()==0)continue;
                while(a[i][a[i].length()-1]=='0'+ans){
                    a[i].pop_back();
                    
                    // cout<<ans<<' '<<i<<' '<<a[i]<<'\n';
                    we=1;
                    if(a[i].length()==0)break;
                }
                if(we)break;
            }
            ans=!ans;
        }
        cout<<win[!ans]<<'\n';
    }
    return 0;
}