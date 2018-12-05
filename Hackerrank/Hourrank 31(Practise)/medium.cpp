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
    ll t=1;
    while(t--){
        ll k=sc,n=sc;
        vl a(n);

        ll i,j;
        f(i,n)a[i]=sc;
        sort1(a);
        vl sum(n,0);
        f(i,n)sum[i]=a[i];
        f(i,n-1)sum[i+1]+=sum[i];
        ld low=0,high=1e18;
        while(low<high){
            ld mid=(low+high)/2.0;
            if(mid==low)
            mid+=0.00000001;
            bool we=0;
            ll kk=k;
            f(i,n){
                if(a[i]>=mid)kk--;
            }
            ld sum=0;
            f(i,n){
                if(a[i]<mid){
                    sum+=a[i];
                }
            }
            // cout<<sum<<' '<<mid<<' '<<kk<<'\n';
            if(kk<=0)
                we=1;
            else
            {
                sum/=kk;
                if(sum>=mid)we=1;
            }
            if(we){
                low=mid;
            }
            else{
                high=mid-0.00000001;
            }
        }
        cout<<fixed<<setprecision(10)<<low<<'\n';
    }
    return 0;
}