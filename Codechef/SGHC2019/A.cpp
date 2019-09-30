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
#define sort(a) sort(a.begin(),a.end())
#define sortn(a,n) sort(a,a+n)
#define vvl vector <vector <ll> >
#define vl vector <ll>
inline ll uscan(){
    ll n=0,c=gc();bool check=0;
    while(c<'0'||c>'9'){if(c=='-')check=1;c=gc();}
    while(c<='9'&&c>='0'){n=n*10+c-'0';c=gc();}
    return check?-n:n;
}
#define sc uscan()
void prin(vector <ll> a){
    for(auto it:a)cout<<it<<' ';pc('\n');
}
void prin(vector <vector <ll> > a){
    for(auto vec:a){for(auto it:vec)cout<<it<<' ';pc('\n');}pc('\n');
}
void prin(vector <pair <ll,ll> > a){
    for(auto it:a)cout<<it.ff<<' '<<it.ss<<'\n';pc('\n');
}
int main()
{
    ll t=sc;
    while(t--){
        ll n=sc, k=sc, p=sc;
        ll i,j;
        vl a(n);
        f(i,n){
            a[i]=sc;
        }
        sort(a);
        ll maxposallowed[n];
        f(i,n){
            for(j = i+1; j < n; j++){
                if(a[j] - a[i] > p)
                    break;
            }
            maxposallowed[i] = j;
        }
        ll dp[n][k], sum[n][k];
        f(i,n){
            sum[i][0] = dp[i][0] = 1;
            if(i)
                sum[i][0] = (sum[i-1][0] + sum[i][0])%mod;
        }
        for(j=1;j<k;j++){
            f(i,n){
                dp[i][j] =  (sum[maxposallowed[i] - 1][j - 1] - sum[i][j - 1] + mod)%mod;
            }
            f(i,n){
                sum[i][j] = dp[i][j];
                if(i){
                    sum[i][j] = (sum[i][j] + sum[i-1][j])%mod;
                }
            }
        }
        cout<<sum[n-1][k-1]<<'\n';
    }
	return 0;
}