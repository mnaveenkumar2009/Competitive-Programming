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
    ll n=uscan();
    bool we=1;
    vector <vector <ll> > a(n),b(n);
    map <ll,ll> maa1,maa2;
    //cout<<maa[0].ss;
    ll i,j,xxx,yyy;
    f(i,n){
        if(!we)break;
        ll x=uscan();
        ll sum=0;
        f(j,x){
            ll ele;
            cin>>ele;
            a[i].pb(ele);
            sum+=ele;
        }
        f(j,x){
            if(maa1[sum-a[i][j]]!=0&&maa2[sum-a[i][j]]!=i+1){
                cout<<"YES\n";
                cout<<maa2[sum-a[i][j]]<<' '<<maa1[sum-a[i][j]]<<'\n';
                cout<<i+1<<' '<<j+1<<'\n';
                we=0;
                break;
            }
            else{
                maa1[sum-a[i][j]]=j+1;
                maa2[sum-a[i][j]]=i+1;
            }
        }
    }
    if(we){        
        cout<<"NO\n";
    }
    return 0;
}