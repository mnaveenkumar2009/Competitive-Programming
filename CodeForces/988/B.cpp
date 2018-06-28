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
    ll n=uscan(),i;
    bool we=1;
    vector <string> a;
    f(i,n){
        string s;
        cin>>s;
        a.pb(s);
    }
    sort(a.begin(),a.end(),f2);
    f(i,n-1){
        if(a[n-i-1].find(a[n-i-2])==string::npos){
            //cout<<a[n-i-1]<<' '<<a[n-i-2]<<'\n';
            we=0;
        }
    }
    if(we){
        cout<<"YES\n";
        f(i,n)cout<<a[i]<<'\n';
    }
    else
    cout<<"NO";
    return 0;
}