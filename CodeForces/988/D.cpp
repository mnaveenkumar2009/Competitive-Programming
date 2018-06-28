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
#define NIL -1
inline ll uscan()
{
    ll n=0,c=gc();
while(c<'0'||c>'9')
c=gc();
while(c<='9'&&c>='0'){
n=n*10+c-'0';
c=gc();}
return n;
}

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
bool f2(string a,string b){
    return a.length()<b.length();
}
int main()
{
    ll n=uscan(),i,j,u;
    vector <ll> a(n);

    f(i,n){
        cin>>a[i];

    }
    sort(a.begin(),a.end()) ;
    vector <ll> ans;
    ans.pb(a[0]);
    /*f(i,n){
        if(a[i]==0){
            continue;
        }
        ll te=log2(a[i]);
        te=1<<te;
        if(a[i]==te){ans.pb(te);break;}
    }*/
    f(i,n){
        f(j,50){
            if(binary_search(a.begin(),a.end(),a[i]+(1LL<<j))){
                vector <ll> temp;
                temp.pb(a[i]);
                temp.pb(a[i]+(1LL<<j));
                if(binary_search(a.begin(),a.end(),a[i]+(1LL<<(j+1)))){
                    temp.pb(a[i]+(1LL<<(j+1)));
                }
                if(temp.size()>ans.size())ans=temp;
            }
        }
    }
    cout<<ans.size()<<'\n';
    f(i,ans.size())cout<<ans[i]<<' ';
    return 0;
}