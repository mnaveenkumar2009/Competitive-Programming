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
int main()
{
    ll n=sc,m=sc,k=sc;
    ll i,j;
    ll a[n][m],sum=0;
    f(i,n){
        f(j,m){
            a[i][j]=sc;
            sum+=a[i][j];
        }
    }
    ll ans[n][m],cur=1;
    f(i,n)f(j,m)ans[i][j]=-1;
    ll cursum=0;
    f(i,n){
        if(i%2){
            f(j,m){
                // cout<<cursum<<'\n';
                if((cursum+a[i][j])*k<=sum){
                    cursum+=a[i][j];
                    if(cur>k)break;
                    ans[i][j]=cur;
                }
                else{
                    // cout<<"e";
                    cursum=a[i][j];
                    cur++;
                    if(cur>k)break;
                    ans[i][j]=cur;
                }
            }
        }
        else{
            for(j=m-1;j>=0;j--){
                // cout<<cursum<<'\n';
                if((cursum+a[i][j])*k<=sum){
                    cursum+=a[i][j];
                    if(cur>k)break;
                    ans[i][j]=cur;
                }
                else{
                    // cout<<"e";
                    cursum=a[i][j];
                    cur++;
                    if(cur>k)break;
                    ans[i][j]=cur;
                }
            }
        }
    }
    f(i,n){
        f(j,m){
            if(ans[i][j]==-1){
                if(i-1>=0){
                    ans[i][j]=ans[i-1][j];
                }
                if(j-1>=0){
                    ans[i][j]=ans[i][j-1];
                }
            }
            cout<<ans[i][j]<<' ';
        }pc('\n');
    }
    return 0;
}
