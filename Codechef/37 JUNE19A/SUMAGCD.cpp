// fft template : https://www.codechef.com/viewsolution/18698974

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
#define double long double
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
inline ll fpow(ll n, ll k) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = (r * n)% mod; n = (n * n) % mod;} return r;}


int main()
{
    int t=sc;
    while(t--){
        int n=sc,i,j,k;
        set <ll> a;
        f(i,n){
            a.insert(sc);
        }
        n=a.size();
        if(n==1){
            cout<<(*a.begin())*2<<'\n';
            continue;
        }
        vector <ll> b;
        auto it=a.end();
        it--;
        int nnn=min(n,10);
        while(nnn--){
            b.pb(*(it--));
        }

        ll ans=0;
        for(auto num:b){
            // cout<<num<<'\n';
            a.erase(num);
            ll gc1=*a.begin();
            for(auto it:a){
                gc1=__gcd(gc1,it);
            }
            ans=max(num+gc1,ans);
            a.insert(num);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
