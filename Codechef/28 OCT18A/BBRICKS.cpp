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
#define vl vector <ll>
#define vvl vector <vector <ll> >
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
vvl dp(2000,vl (2000,-1));
ll f2(ll n,ll k){
    // cout<<n<<' '<<k<<'\n';
    // if(k<0)
    //     return 0;
    if(n<=0)return 0;
    // if(k==0)return 1;
    if(k>n)return 0;
    if(k==0)return 1;
    if(dp[n][k]!=-1)
        return dp[n][k];
    dp[n][k]=(f2(n-1,k)+f2(n-1,k-1)+f2(n-2,k-1))%mod;
    // for(ll i=1;n-i-1>=0;i++){
    //     dp[n][k]= (dp[n][k]+2*f2(n-i-1,k-i))%mod;
    // }
    // cout<<dp[n][k]<<'\n';
    return dp[n][k];
}
vvl dp2(3000,vl (3000,-1));
ll D(ll n,ll k){
    if(n<0)return 0;
    if(k<0)return 0;
    if(dp2[n][k]!=-1)
        return dp2[n][k];
    if(n==0||k==n){
        return 1;
    }
    dp2[(n)][(k)] = (D(n-1, k-1)+D(n-2, k-1)+D(n-1, k))%mod;
    return dp2[n][k];
}

ll sum[2000][2000];

int main()
{
    t=sc;
    dp[1][1]=2;
    dp[2][2]=2;
    dp[2][1]=4;
    ll i,j;
    f(i,1000){
        f(j,1000){
            sum[i][j]=f2(i,j);
        }
    }
    f(i,1000){
        f(j,1000){
            if(i)
                sum[i][j]+=sum[i-1][j];
        }
    }

    // f(i,20){
    //     f(j,20){
    //         cout<<sum[j][i]<<' ';
    //     }cout<<'\n';
    // }
    while(t--){
        ll n=sc,k=sc;
        cout<<f2(n,k)<<'\n';
        // cout<<sum[n][k]<<'\n';
        cout<<D(n,k)<<'\n';
        ll i,j;
    }
    return 0;
}