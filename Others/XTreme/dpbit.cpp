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
bool we=1;
void prin(vector <ll> a){
    ll i;
    f(i,a.size()){
        cout<<a[i]<<' ';
    }pc('\n');
}
ll stscan()
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
    if(c=='\n')we=0;
    return n+(-2*check*n);
}
#define sc uscan()

#define bpc __builtin_popcountll
vector <ll> adj[23];
ll dp[25][25][1LL<<8];
vector <bool> vis(500000,0);
ll n;
ll ccc=0;

int main() {
    n=sc;
    ll i,j,k;
    ll mask=(1LL<<8)-1;
    f(i,n){
        f(j,n){
            f(k,mask+1){
                dp[i][j][k]=-1;
            }
        }
    }
    f(i,n){
        f(j,n){
            dp[i][j][0]=0;
        }
    }
    f(i,n-1){
        we=1;
        while(we){
            ll x=stscan();
            adj[i].pb(x);
        }
    }
    ll xxxxx;
    while(cin>>xxxxx){
        adj[n-1].pb(xxxxx);
    }
    // f(i,n){
    //     prin(adj[i]);
    // }
    ll mask2;
    f(mask2,1LL<<7){
        ll kkkk=30;
        while(kkkk--){
            f(i,n){
                f(j,n){
                    ll mask=mask2;
                    
                    if(i>=n-7){
                        if(mask&(1LL<<(7+i-n))){
                            continue;
                        }
                    }
                    if(j>=n-7){
                        if(mask&(1LL<<(7+j-n))){
                            continue;
                        }
                    }
                    dp[i][j][mask]=0;
                    for(auto edg:adj[i]){
                        if(edg>=n-7){
                            if(mask&(1LL<<(7+edg-n))){
                                ll xxx=bpc(mask);
                                dp[i][j][mask]=max(xxx-dp[j][edg][mask^(1LL<<(7+edg-n))],dp[i][j][mask]);
                            }
                            else{
                                if(dp[j][edg][mask]!=-1)
                                    dp[i][j][mask]=max(dp[i][j][mask],bpc(mask)-dp[j][edg][mask]);
                            }
                        }
                        else{
                            if(dp[j][edg][mask]!=-1)
                                dp[i][j][mask]=max(dp[i][j][mask],bpc(mask)-dp[j][edg][mask]);
                        }
                    }
                }
            }
        }
    }
    cout<<dp[0][0][(1<<7)-1];
    return 0;
}
