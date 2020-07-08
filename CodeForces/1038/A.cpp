#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ld long double
#define gc getchar
#define pc putchar
#define f(i,n) for(i=0;i<n;i++)
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


int main() {
    ll t=1;
    ll kkk=0;
    f(kkk,t){
        ll n=uscan(),k=uscan(),i,j;
        string s;
        ll a[n][k];
        cin>>s;
        f(i,n){
            f(j,k){
                a[i][j]=0;
            }
        }

        f(i,n){
            a[i][s[i]-'A']=1;
        }
        f(i,n-1){
            f(j,k){
                a[i+1][j]+=a[i][j];
            }
        }
        ll temp=0,ans=0;
        f(i,n){
            temp=INT_MAX;
            f(j,k){
                temp=min(temp,a[i][j]);
            }
            ans=max(ans,temp*k);
        }
        // f(i,n){
        //     f(j,k){
        //         cout<<a[i][j]<<' ';
        //     }
        // }
        cout<<ans<<'\n';
    }
    return 0;
}